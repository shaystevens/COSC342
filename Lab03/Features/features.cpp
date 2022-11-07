#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Timer.h"

cv::Mat translationMatrix(double dx, double dy){
	cv::Mat T = cv::Mat::eye(3, 3, CV_64F);

	T.at<double>(0, 2) = dx;
	T.at<double>(1, 2) = dy;

	return T;
}

cv::Mat rotationMatrix(double angle) {
	//Create a 3 x 3 matrix of doubles (64-bit floating point values)
	cv::Mat M(3, 3, CV_64F);

	//pi constant
	const double pi = 3.14159265358979311599796346854;

	//convert degrees angle to radians for trigonometric functions
	double radians = angle*pi/180;

	//Iterate through matrix and set every value to 0
	for (int r = 0; r < M.rows; ++r) {
		for (int c = 0; c < M.cols; ++c) {
			M.at<double>(r,c) = 0;
		}
	}

	M.at<double>(0,0) = cos(radians);
	M.at<double>(0,1) = -sin(radians);
	M.at<double>(1,0) = sin(radians);
	M.at<double>(1,1) = cos(radians);
	M.at<double>(2,2) = 1;

	return M;
}

int main(int argc, char* argv[]) {

	//The timer code reads how long it takes to read the images from disk
	Timer myTimer;
	myTimer.reset();
	cv::Mat image1 = cv::imread("../image1.jpg");
	cv::Mat image2 = cv::imread("../image2.jpg");
	double elapsedTime = myTimer.read();
	std::cout << "It took " << elapsedTime << " seconds to read files from disk" << std::endl;

	//Check if images are empty if so produce an error
	if (image1.empty()) {
		std::cerr << "Could not load image from image1.jpg" << std::endl;
		return -1;
	}
	if (image2.empty()) {
		std::cerr << "Could not load image from image2.jpg" << std::endl;
		return -1;
	}

	//Detect features in image 1 using SIFT
	cv::Ptr<cv::FeatureDetector> detector1 = cv::SIFT::create();
	std::vector<cv::KeyPoint> keypoints1;
	cv::Mat descriptors1;
	detector1->detectAndCompute(image1, cv::noArray(), keypoints1, descriptors1);
	std::cout << "Found " << keypoints1.size() << " features in image 1" << std::endl;

	//Draw the features on image 1 on a new image display
	cv::Mat kptImage1;
	cv::drawKeypoints(image1, keypoints1, kptImage1, cv::Scalar(0, 255, 0), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	cv::imshow("Display 1 features", kptImage1);
	cv::waitKey();

	//Detect features in image 2 using SIFT
	cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
	std::vector<cv::KeyPoint> keypoints2;
	cv::Mat descriptors2;
	detector2->detectAndCompute(image2, cv::noArray(), keypoints2, descriptors2);
	std::cout << "Found " << keypoints2.size() << " features in image 2" << std::endl;

	//Draw the features on image 1 on a new image display
	cv::Mat kptImage2;
	cv::drawKeypoints(image2, keypoints2, kptImage2, cv::Scalar(0, 255, 0), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	cv::imshow("Dsiplay 2 features", kptImage2);
	cv::waitKey();

	//Vectors to hold the goodPoints
	std::vector<cv::Point2f> goodPts1, goodPts2;

	//Match the features in both images
	myTimer.reset();
	cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
	std::vector<std::vector<cv::DMatch>> matches;
	matcher->knnMatch(descriptors1, descriptors2, matches, 2);
	std::vector<cv::DMatch> goodMatches;
	for(const auto& match : matches) {
		if(match[0].distance < 0.8 * match[1].distance){
			goodMatches.push_back(match[0]);
			goodPts1.push_back(keypoints1[match[0].queryIdx].pt);
			goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
		}
	}
	elapsedTime = myTimer.read();
	std::cout << "It took " << elapsedTime << " seconds to find matches " << matches.size() << std::endl;

	//Homography between the two images
	std::vector<unsigned char> inliers;
	cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC);
	std::cout << H << std::endl;

	//mosiac = translationMatrix(-240, -320) * mosiac;
	
	cv::Mat target(775, 2000, CV_8UC3);
	for (int v = 0; v < target.size().height; ++v) {
		for (int u = 0; u < target.size().width; ++u) {
			// The column vector [u, v, 1]
			cv::Mat s(3, 1, CV_64F);
			s.at<double>(0,0) = u;
			s.at<double>(1,0) = v;
			s.at<double>(2,0) = 1;

			cv::Mat t = (translationMatrix(800, 0)).inv()*s;
			int u_ = (int) (t.at<double>(0) / t.at<double>(2) + 0.5);
			int v_ = (int) (t.at<double>(1) / t.at<double>(2) + 0.5);
			if(!(u_ > (image1.size().width-1) || u_ < 0 || v_ > (image1.size().height-1) || v_ < 0)){
				target.at<cv::Vec3b>(v, u) = image1.at<cv::Vec3b>(v_, u_);
			}
		}
	}

	cv::Mat image2Mosiac(775, 2000, CV_8UC3);
	for (int v = 0; v < image2Mosiac.size().height; ++v) {
		for (int u = 0; u < image2Mosiac.size().width; ++u) {
			// The column vector [u, v, 1]
			cv::Mat s(3, 1, CV_64F);
			s.at<double>(0,0) = u;
			s.at<double>(1,0) = v;
			s.at<double>(2,0) = 1;

			cv::Mat t = (translationMatrix(970, 0)).inv()*s;
			int u_ = (int) (t.at<double>(0) / t.at<double>(2) + 0.5);
			int v_ = (int) (t.at<double>(1) / t.at<double>(2) + 0.5);
			if(!(u_ > (image2.size().width-1) || u_ < 0 || v_ > (image2.size().height-1) || v_ < 0)){
				image2Mosiac.at<cv::Vec3b>(v, u) = image2.at<cv::Vec3b>(v_, u_);
			}
		}
	}

	//Create the mosacic
	cv::Mat mosiac = target.clone();
	cv::warpPerspective(image2Mosiac, mosiac, H, mosiac.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

	/*cv::Mat framedMosiac(1200, 2400, CV_8UC3);
	for (int v = 0; v < framedMosiac.size().height; ++v) {
		for (int u = 0; u < framedMosiac.size().width; ++u) {
			// The column vector [u, v, 1]
			cv::Mat s(3, 1, CV_64F);
			s.at<double>(0,0) = u;
			s.at<double>(1,0) = v;
			s.at<double>(2,0) = 1;

			
			//rotate image 45 degrees in it's centre
			cv::Mat t = (translationMatrix(800, -200)).inv()*s;
			int u_ = (int) (t.at<double>(0) / t.at<double>(2) + 0.5);
			int v_ = (int) (t.at<double>(1) / t.at<double>(2) + 0.5);
			if(!(u_ > (mosiac.size().width-1) || u_ < 0 || v_ > (mosiac.size().height-1) || v_ < 0)){
				framedMosiac.at<cv::Vec3b>(v, u) = mosiac.at<cv::Vec3b>(v_, u_);
			}
		}
	}*/

	//Draw matches
	cv::Mat matchImg;
	cv::drawMatches(image1, keypoints1, image2, keypoints2, goodMatches, matchImg);
	cv::namedWindow("Matches");
	cv::imshow("Matches", matchImg);

	//Display images
	cv::namedWindow("Display 1");
	cv::imshow("Display 1", image1);
	cv::imshow("Display 2", image2);
	cv::imshow("Mosiac", mosiac);
	cv::waitKey();

	return 0;
}