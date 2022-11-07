#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

#include "CalibrationIO.h"

bool isValid(const cv::Vec3d& xyz, float disparity) {
	// Check for NaNs etc. in Z
	if (!isnormal(xyz[2])) {
		return false;
	}

	if(disparity < 0){
		return false;
	}

	// Other checks can go here
	return true;
}

int main(int argc, char *argv[]) {

	std::string calibrationFile = "/Users/shaystevens/Desktop/COSC342/Lab06/Calibration/Calibration/stereoCalibration.txt"; // This will depend on where you saved it
	std::string image1File = "../bell_left.jpg";
	std::string image2File = "../bell_right.jpg";

	cv::Mat K1, K2, R, T, R1, R2, P1, P2, Q;
	std::vector<double> d1, d2;
	readStereoCalibration(calibrationFile, K1, d1, K2, d2, R, T);

	std::cout << "K1" << std::endl << K1 << std::endl;
	std::cout << "K2" << std::endl << K2 << std::endl;
	std::cout << "R" << std::endl << R << std::endl;
	std::cout << "T" << std::endl << T << std::endl;

	cv::Mat I1 = cv::imread(image1File);
	cv::Mat I2 = cv::imread(image2File);

	cv::Size imageSize(1920, 1080);

	//Stereo rectify
	cv::stereoRectify(K1, d1, K2, d2, imageSize, R, T, R1, R2, P1, P2, Q);

	cv::Mat map1(1920, 1080, CV_32F);
	cv::Mat map2(1920, 1080, CV_32F);
	cv::Mat map3(1920, 1080, CV_32F);
	cv::Mat map4(1920, 1080, CV_32F);

	cv::initUndistortRectifyMap(K1, d1, R1, P1, imageSize, CV_32F, map1, map2);
	cv::initUndistortRectifyMap(K2, d2, R2, P2, imageSize, CV_32F, map3, map4);

	cv::Mat target1, target2;

	cv::remap(I1, target1, map1, map2, cv::INTER_LINEAR);
	cv::remap(I2, target2, map3, map4, cv::INTER_LINEAR);

	//Change image size
	cv::Mat smallTarget1, smallTarget2;
	cv::resize(target1, smallTarget1, target1.size()/4, 0, 0, cv::INTER_AREA);
	cv::resize(target2, smallTarget2, target2.size()/4, 0, 0, cv::INTER_AREA);

	//Block matching
	int maxDisparity = 64;
	int blockSize = 21;
	int semiBlockSize = 11;
	cv::Ptr<cv::StereoBM> blockMatcher = cv::StereoBM::create(maxDisparity, blockSize);

	//Turn image colour grey
	cv::Mat image1, image2;
	cv::cvtColor(smallTarget1, image1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(smallTarget2, image2, cv::COLOR_BGR2GRAY);
	cv::Mat disparity, disparity2;
	blockMatcher->compute(image1, image2, disparity);

	//Disparity
	/*cv::Mat display, display2;
	disparity.convertTo(display, CV_8UC1, 255.0 / (16*maxDisparity));*/

	//Semi global Matching
	/*
	cv::Ptr<cv::StereoSGBM> sgMatcher = cv::StereoSGBM::create(0, maxDisparity, semiBlockSize);
	sgMatcher->compute(smallTarget1, smallTarget2, disparity2);
	disparity2.convertTo(display2, CV_8UC1, 255.0 / (16*maxDisparity));*/

	cv::Mat disparityFullBlock, disparityFullSemi;
	cv::resize(disparity, disparityFullBlock, imageSize, 0, 0, cv::INTER_NEAREST);
	//cv::resize(disparity2, disparityFullSemi, imageSize, 0, 0, cv::INTER_NEAREST);

	cv::Mat disparityFloat(imageSize, CV_32F);
	disparityFullBlock.convertTo(disparityFloat, CV_32F, 1./16.0);

	//cv::Mat disparityFloat2(imageSize, CV_32F);
	//disparityFullSemi.convertTo(disparityFloat2, CV_32F, 1./16.0);

	cv::Mat points3D(imageSize, CV_32FC3);
	cv::reprojectImageTo3D(disparityFloat, points3D, Q);

	std::ofstream fout("model.ply");
	fout << "ply\n"
	<< "format ascii 1.0\n"
	<< "element vertex " << points3D.size().area() << "\n"
	<< "property float x\n"
	<< "property float y\n"
	<< "property float z\n"
	<< "property uchar red\n"
	<< "property uchar green\n"
	<< "property uchar blue\n"
	<< "end_header\n";
	
	for (int y=0; y < points3D.size().height; ++y){
		for (int x=0; x < points3D.size().width; ++x){
			cv::Vec3f xyz = points3D.at<cv::Vec3f>(y, x);
			float disparityFloat = disparityFullBlock.at<float>(y,x);
			if (isValid(xyz, disparityFloat)) {
				// Write location data for this point
                fout << xyz[0] << " " << xyz[1] << " " << xyz[2] << " ";
                // Write colour data for this point
                cv::Vec3b rgb = I1.at<cv::Vec3b>(y, x);
                // Note: OpenCV uses BGR colour
                fout << int(rgb[2]) << " " << int(rgb[1])
                     << " " << int(rgb[0]) << "\n";
			}
		}
	}

	fout.close();

	cv::namedWindow("Left");
	cv::namedWindow("Right");
	cv::imshow("Left", I1);
	cv::imshow("Right", I2);
	cv::imshow("Target 1", target1);
	cv::imshow("Target 2", target2);
	//cv::imshow("Block Match", display);
	//cv::imshow("Semi Global Match", display2);
	cv::waitKey();

	return 0;

}
