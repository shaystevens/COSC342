#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

#include "CalibrationIO.h"

int main(int argc, char *argv[]) {

	//Command line help message
	if(argc != 7){
		std::cerr << "\nError expected 6 arguments." << std::endl;
		std::cerr << "Usage:\n" << std::endl;
		std::cerr << "stereo <calibration file> <left image> <right image> 'Block' or 'Semi-Global' <maximum disparity> <block size>\n" << std::endl;
		return -1;

	}

	cv::Mat K1, K2, R, T, R1, R2, P1, P2, Q;
	std::vector<double> d1, d2;
	readStereoCalibration(argv[1], K1, d1, K2, d2, R, T);

	std::cout << "K1" << std::endl << K1 << std::endl;
	std::cout << "K2" << std::endl << K2 << std::endl;
	std::cout << "R" << std::endl << R << std::endl;
	std::cout << "T" << std::endl << T << std::endl;

	//Read left and right images
	cv::Mat I1 = cv::imread(argv[2]);
	cv::Mat I2 = cv::imread(argv[3]);
	cv::Size imageSize(1920, 1080);

	//Stereo rectify
	cv::stereoRectify(K1, d1, K2, d2, imageSize, R, T, R1, R2, P1, P2, Q);
	cv::Mat map1(1920, 1080, CV_32F);
	cv::Mat map2(1920, 1080, CV_32F);
	cv::Mat map3(1920, 1080, CV_32F);
	cv::Mat map4(1920, 1080, CV_32F);
	cv::initUndistortRectifyMap(K1, d1, R1, P1, imageSize, CV_32F, map1, map2);
	cv::initUndistortRectifyMap(K2, d2, R2, P2, imageSize, CV_32F, map3, map4);

	//Remap images to targets
	cv::Mat target1, target2;
	cv::remap(I1, target1, map1, map2, cv::INTER_LINEAR);
	cv::remap(I2, target2, map3, map4, cv::INTER_LINEAR);

	//Shrink images
	cv::Mat smallTarget1, smallTarget2;
	cv::resize(target1, smallTarget1, target1.size()/4, 0, 0, cv::INTER_AREA);
	cv::resize(target2, smallTarget2, target2.size()/4, 0, 0, cv::INTER_AREA);

	//Declare maximum disparity and blocksize
	int maximumDisparity = atoi(argv[5]);
	int blockSize = atoi(argv[6]);

	//Change images colour grey
	cv::Mat image1, image2;
	cv::cvtColor(smallTarget1, image1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(smallTarget2, image2, cv::COLOR_BGR2GRAY);

	//Disparity and display
	cv::Mat disparity;
	cv::Mat display;
	std::string estimationMethod = argv[4];

	if(estimationMethod == "Block"){ 
		//Block matching
		cv::Ptr<cv::StereoBM> blockMatcher = cv::StereoBM::create(maximumDisparity, blockSize);
		blockMatcher->compute(image1, image2, disparity);
		disparity.convertTo(display, CV_8UC1, 255.0 / (16*maximumDisparity));

	}else if(estimationMethod == "Semi-Global"){
		//Semi global Matching
		int p1 = 8*blockSize^2;
		int p2 = 32*blockSize^2;

		cv::Ptr<cv::StereoSGBM> sgMatcher = cv::StereoSGBM::create(0, maximumDisparity, blockSize, p1, p2);
		sgMatcher->setMode(cv::StereoSGBM::MODE_HH);
		sgMatcher->compute(smallTarget1, smallTarget2, disparity);
		disparity.convertTo(display, CV_8UC1, 255.0 / (16*maximumDisparity));
	}

	//Display windows
	cv::namedWindow("Left");
	cv::namedWindow("Right");
	cv::imshow("Left", I1);
	cv::imshow("Right", I2);
	cv::imshow("Target 1", target1);
	cv::imshow("Target 2", target2);
	cv::imshow(argv[4], display);
	cv::waitKey();

	return 0;

}
