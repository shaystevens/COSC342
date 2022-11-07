#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
	std::string filename = "../test.jpg";
	
	//load image file
	cv::Mat image = cv::imread(filename);
	
	//Make same size copy of image, but single channel
	cv::Mat greyscale(image.size(), CV_8UC1);

	if (image.empty()) {
		std::cerr << "Could not load image from " << filename << std::endl;
		return -1;
	}

	//Basic greyscale conversion
	for (int y = 0; y < image.size().height; ++y){
		for(int x = 0; x < image.size().width; ++x){
			cv::Vec3b colour = image.at<cv::Vec3b>(y,x);
			greyscale.at<unsigned char>(y,x) =
				(unsigned char)(0.1 * colour[0] + 0.6 * colour[1] + 0.3 * colour[2]);
		}
	}

	//Save the result
	cv::imwrite("../grey.png", greyscale);

	return 0;
}