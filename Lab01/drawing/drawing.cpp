#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
	//Make 800x600 image and set colour to green
	cv::Mat image(600, 800, CV_8UC3);
	//                  blue green red
	image.setTo(cv::Scalar(0,255,0));

	//Draw blue circle
	cv::circle(image, cv::Point(400,300), 200, cv::Scalar(255,0,0), -1);

	//Draw white circle
	cv::circle(image, cv::Point(400,300), 100, cv::Scalar(255,255,255), 10);

	cv::namedWindow("Display");
	cv::imshow("Display", image);
	cv::waitKey();
	
	return 0;
}