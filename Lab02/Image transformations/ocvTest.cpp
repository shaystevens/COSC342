#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

cv::Mat scaleMatrix(double s) {
	//Create a 3 x 3 matrix of doubles (64-bit floating point values)
	cv::Mat M(3, 3, CV_64F);

	//Iterate through matrix and set every value to 0
	for (int r = 0; r < M.rows; ++r) {
		for (int c = 0; c < M.cols; ++c) {
			M.at<double>(r,c) = 0;
		}
	}
	
	//Set scaling identity matrix values
	M.at<double>(0,0) = s;
	M.at<double>(1,1) = s;
	M.at<double>(2,2) = 1;

	return M;
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

cv::Mat translationMatrix(double dx, double dy){
	cv::Mat T = cv::Mat::eye(3, 3, CV_64F);

	T.at<double>(0, 2) = dx;
	T.at<double>(1, 2) = dy;

	return T;
}

double max(double x, double y, double z, double w){
	if(x > y && x > z && x > w){
		return x;
	}else if(y > x && y > z && y > w){
		return y;
	}else if(z > x && z > y && z > w){
		return z;
	}else{
		return w;
	}
}

double min(double x, double y, double z, double w){
	if(x < y && x < z && x < w){
		return x;
	}else if(y < x && y < z && y < w){
		return y;
	}else if(z < x && z < y && z < w){
		return z;
	}else{
		return w;
	}
}

int main(int argc, char* argv[]) {
	std::string filename = "../test.jpg";
	
	//load image file
	cv::Mat original = cv::imread(filename);
	//cv::Mat target (original.size(), CV_8UC3);

	cv::Mat T(3,3, CV_64F);
	// code to set up T goes here.
	T = translationMatrix(320, 240) * rotationMatrix(45) * translationMatrix(-320, -240);

	/** c1, c2, c3, c4 are the original corners of the image */ 
	//c1
	cv::Mat c1(3, 1, CV_64F);
	c1.at<double>(0,0) = 0;
	c1.at<double>(1,0) = 0;
	c1.at<double>(2,0) = 1;

	//c2
	cv::Mat c2(3, 1, CV_64F);
	c2.at<double>(0,0) = 640;
	c2.at<double>(1,0) = 0;
	c2.at<double>(2,0) = 1;

	//c3
	cv::Mat c3(3, 1, CV_64F);
	c3.at<double>(0,0) = 640;
	c3.at<double>(1,0) = 480;
	c3.at<double>(2,0) = 1;

	//c4
	cv::Mat c4(3, 1, CV_64F);
	c4.at<double>(0,0) = 0;
	c4.at<double>(1,0) = 480;
	c4.at<double>(2,0) = 1;

	/** c1', c2', c3', c4' are the transformed corners of the image */
	//c1'
	cv::Mat c1_ = T*c1;

	//c2'
	cv::Mat c2_ = T*c2;

	//c3'
	cv::Mat c3_ = T*c3;

	//c4'
	cv::Mat c4_ = T*c4;

	//u-
	double u_minus = min(c1_.at<double>(0,0), c2_.at<double>(0,0), c3_.at<double>(0,0), c4_.at<double>(0,0));

	//u+
	double u_plus = max(c1_.at<double>(0,0), c2_.at<double>(0,0), c3_.at<double>(0,0), c4_.at<double>(0,0));

	//v-
	double v_minus = min(c1_.at<double>(1,0), c2_.at<double>(1,0), c3_.at<double>(1,0), c4_.at<double>(1,0));

	//v+
	double v_plus = max(c1_.at<double>(1,0), c2_.at<double>(1,0), c3_.at<double>(1,0), c4_.at<double>(1,0));

	cv::Mat target(u_plus - u_minus, v_plus - v_minus, CV_8UC3);

	for (int v = 0; v < target.size().height; ++v) {
		for (int u = 0; u < target.size().width; ++u) {
			// The column vector [u, v, 1]
			cv::Mat s(3, 1, CV_64F);
			s.at<double>(0,0) = u;
			s.at<double>(1,0) = v;
			s.at<double>(2,0) = 1;

			
			//rotate image 45 degrees in it's centre
			cv::Mat t = (translationMatrix(-u_minus, -v_minus)*T).inv()*s;
			int u_ = (int) (t.at<double>(0) / t.at<double>(2) + 0.5);
			int v_ = (int) (t.at<double>(1) / t.at<double>(2) + 0.5);
			if(!(u_ > (original.size().width-1) || u_ < 0 || v_ > (original.size().height-1) || v_ < 0)){
				target.at<cv::Vec3b>(v, u) = original.at<cv::Vec3b>(v_, u_);
			}
		}
	}

	cv::namedWindow("Original");
	cv::imshow("Original", original);
	cv::waitKey();

	cv::namedWindow("Target");
	cv::imshow("Target", target);
	cv::waitKey();

	return 0;
}