#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Timer.h"

int main(int argc, char* argv[]) {

	//Couch photos
	cv::Mat couch1 = cv::imread("../Images/Couchrotation/couchrotation1.JPG");
	cv::Mat couch2 = cv::imread("../Images/Couchrotation/couchrotation2.JPG");
	cv::Mat couch3 = cv::imread("../Images/Couchrotation/couchrotation3.JPG");
	cv::Mat couch4 = cv::imread("../Images/Couchrotation/couchrotation4.JPG");
	cv::Mat couch5 = cv::imread("../Images/Couchrotation/couchrotation5.JPG");
	cv::Mat couch6 = cv::imread("../Images/Couchrotation/couchrotation6.JPG");
	cv::Mat couch7 = cv::imread("../Images/Couchrotation/couchrotation7.JPG");
	cv::Mat couch8 = cv::imread("../Images/Couchrotation/couchrotation8.JPG");
	cv::Mat couch9 = cv::imread("../Images/Couchrotation/couchrotation9.JPG");
	cv::Mat couch10 = cv::imread("../Images/Couchrotation/couchrotation10.JPG");

	//Forest photos
	cv::Mat forest1 = cv::imread("../Images/Forestrotation/forestrotation1.JPG");
	cv::Mat forest2 = cv::imread("../Images/Forestrotation/forestrotation2.JPG");
	cv::Mat forest3 = cv::imread("../Images/Forestrotation/forestrotation3.JPG");
	cv::Mat forest4 = cv::imread("../Images/Forestrotation/forestrotation4.JPG");
	cv::Mat forest5 = cv::imread("../Images/Forestrotation/forestrotation5.JPG");
	cv::Mat forest6 = cv::imread("../Images/Forestrotation/forestrotation6.JPG");
	cv::Mat forest7 = cv::imread("../Images/Forestrotation/forestrotation7.JPG");
	cv::Mat forest8 = cv::imread("../Images/Forestrotation/forestrotation8.JPG");
	cv::Mat forest9 = cv::imread("../Images/Forestrotation/forestrotation9.JPG");
	cv::Mat forest10 = cv::imread("../Images/Forestrotation/forestrotation10.JPG");

	//Gas photos
	cv::Mat gas1 = cv::imread("../Images/Gasstationrotation/gasstationrotation1.JPG");
	cv::Mat gas2 = cv::imread("../Images/Gasstationrotation/gasstationrotation2.JPG");
	cv::Mat gas3 = cv::imread("../Images/Gasstationrotation/gasstationrotation3.JPG");
	cv::Mat gas4 = cv::imread("../Images/Gasstationrotation/gasstationrotation4.JPG");
	cv::Mat gas5 = cv::imread("../Images/Gasstationrotation/gasstationrotation5.JPG");
	cv::Mat gas6 = cv::imread("../Images/Gasstationrotation/gasstationrotation6.JPG");
	cv::Mat gas7 = cv::imread("../Images/Gasstationrotation/gasstationrotation7.JPG");
	cv::Mat gas8 = cv::imread("../Images/Gasstationrotation/gasstationrotation8.JPG");
	cv::Mat gas9 = cv::imread("../Images/Gasstationrotation/gasstationrotation9.JPG");
	cv::Mat gas10 = cv::imread("../Images/Gasstationrotation/gasstationrotation10.JPG");

	//Field photos
	cv::Mat field1 = cv::imread("../Images/Fieldrotation/fieldrotation1.JPG");
	cv::Mat field2 = cv::imread("../Images/Fieldrotation/fieldrotation2.JPG");
	cv::Mat field3 = cv::imread("../Images/Fieldrotation/fieldrotation3.JPG");
	cv::Mat field4 = cv::imread("../Images/Fieldrotation/fieldrotation4.JPG");
	cv::Mat field5 = cv::imread("../Images/Fieldrotation/fieldrotation5.JPG");
	cv::Mat field6 = cv::imread("../Images/Fieldrotation/fieldrotation6.JPG");
	cv::Mat field7 = cv::imread("../Images/Fieldrotation/fieldrotation7.JPG");
	cv::Mat field8 = cv::imread("../Images/Fieldrotation/fieldrotation8.JPG");
	cv::Mat field9 = cv::imread("../Images/Fieldrotation/fieldrotation9.JPG");
	cv::Mat field10 = cv::imread("../Images/Fieldrotation/fieldrotation10.JPG");

	//Garden photos
	cv::Mat garden1 = cv::imread("../Images/Gardenrotation/gardenrotation1.JPG");
	cv::Mat garden2 = cv::imread("../Images/Gardenrotation/gardenrotation2.JPG");
	cv::Mat garden3 = cv::imread("../Images/Gardenrotation/gardenrotation3.JPG");
	cv::Mat garden4 = cv::imread("../Images/Gardenrotation/gardenrotation4.JPG");
	cv::Mat garden5 = cv::imread("../Images/Gardenrotation/gardenrotation5.JPG");
	cv::Mat garden6 = cv::imread("../Images/Gardenrotation/gardenrotation6.JPG");
	cv::Mat garden7 = cv::imread("../Images/Gardenrotation/gardenrotation7.JPG");
	cv::Mat garden8 = cv::imread("../Images/Gardenrotation/gardenrotation8.JPG");
	cv::Mat garden9 = cv::imread("../Images/Gardenrotation/gardenrotation9.JPG");
	cv::Mat garden10 = cv::imread("../Images/Gardenrotation/gardenrotation10.JPG");

	//The timer code reads how long it takes to read the images from disk
	Timer myTimer;
	double totalTime = 0;
	double totalMatches = 0;
	double totalFeatures = 0;
	
	/*
	std::cout << "\n<><><><><><><><><><><><><><><>Couch<><><><><><><><><><><><><><><><><>\n" << std::endl;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;


		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}
	}

	std::cout << "\n-------------------------BruteForce matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << std::endl;

	totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;


		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(couch9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(couch10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}
	}

	std::cout << "\n-------------------------Flann-Based Matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << "\n" << std::endl;*/

	/*totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;*/
	/*std::cout << "\n<><><><><><><><><><><><><><><>Forest<><><><><><><><><><><><><><><><><>\n" << std::endl;
	
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}
	}

	std::cout << "\n-------------------------BruteForce matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << std::endl;
	
	totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
		
		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(forest9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(forest10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;


		}
	}

	std::cout << "\n-------------------------Flann-Based Matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << "\n" << std::endl;*/

	/*
	std::cout << "\n<><><><><><><><><><><><><><><>Gas<><><><><><><><><><><><><><><><><>\n" << std::endl;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}
	}

	std::cout << "\n-------------------------BruteForce matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << std::endl;

	totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

			
		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(gas9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(gas10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}
	}

	std::cout << "\n-------------------------Flann-Based Matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << "\n" << std::endl;*/

	/*std::cout << "\n<><><><><><><><><><><><><><><>Field<><><><><><><><><><><><><><><><><>\n" << std::endl;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}
	}

	std::cout << "\n-------------------------BruteForce matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << std::endl;

	totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
		
		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(field9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(field10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}
	}

	std::cout << "\n-------------------------Flann-Based Matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << "\n" << std::endl;*/

	std::cout << "\n<><><><><><><><><><><><><><><>Garden<><><><><><><><><><><><><><><><><>\n" << std::endl;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}
	}

	std::cout << "\n-------------------------BruteForce matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << std::endl;

	totalTime = 0;
	totalMatches = 0;
	totalFeatures = 0;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden1, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden2, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==3){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden3, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden4, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}else if(i==5){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden5, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden6, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

			
		}else if(i==7){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden7, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden8, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;
			
		}else{
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden9, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden10, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);

			double elapsedTime = myTimer.read();
			totalMatches += matches.size();
			totalTime += elapsedTime;

		}
	}


	std::cout << "\n-------------------------Flann-Based Matcher---------------------------" << std::endl;
	std::cout << "The average features found is  " << totalFeatures/10 << std::endl; 
	std::cout << "The average time taken to find " << totalMatches/5 << " matches is " << totalTime/10 << "\n" << std::endl;

	/*
	std::cout << "\n<><><><><><><><><><><><><><><>Garden<><><><><><><><><><><><><><><><><>\n" << std::endl;
	for(int i=1; i < 11; i+=2){
		if(i==1){
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden6, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden7, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;
			for(const auto& match : matches) {
				if(match[0].distance < 0.8 * match[1].distance){
					goodMatches.push_back(match[0]);
					goodPts1.push_back(keypoints[match[0].queryIdx].pt);
					goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
				}
			}

			double elapsedTime = myTimer.read();
			totalMatches += goodMatches.size();
			totalTime += elapsedTime;

			//Homography between the two images
			myTimer.reset();
			std::vector<unsigned char> inliers;
			cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC, 3.0);
			double time = myTimer.read();
			std::cout << "It took " << time << " when threshold is 3 " << std::endl;

			cv::Mat mosaic = garden6.clone();
			cv::warpPerspective(garden7, mosaic, H, mosaic.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

			cv::imshow("Mosiac 3", mosaic);
			cv::waitKey();

		}else if(i==3){
			std::cout << "\n-------------------------------------------------------" << std::endl;
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden6, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden7, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;
			for(const auto& match : matches) {
				if(match[0].distance < 0.8 * match[1].distance){
					goodMatches.push_back(match[0]);
					goodPts1.push_back(keypoints[match[0].queryIdx].pt);
					goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
				}
			}

			double elapsedTime = myTimer.read();
			totalMatches += goodMatches.size();
			totalTime += elapsedTime;

			myTimer.reset();
			std::vector<unsigned char> inliers;
			cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC, 4.0);
			double time = myTimer.read();
			std::cout << "It took " << time << " when threshold is 4 " << std::endl;

			cv::Mat mosaic = garden6.clone();
			cv::warpPerspective(garden7, mosaic, H, mosaic.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

			cv::imshow("Mosiac 4", mosaic);
			cv::waitKey();

		}else if(i==5){
			std::cout << "\n-------------------------------------------------------" << std::endl;
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden6, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden7, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;
			for(const auto& match : matches) {
				if(match[0].distance < 0.8 * match[1].distance){
					goodMatches.push_back(match[0]);
					goodPts1.push_back(keypoints[match[0].queryIdx].pt);
					goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
				}
			}

			double elapsedTime = myTimer.read();
			totalMatches += goodMatches.size();
			totalTime += elapsedTime;

			//Homography between the two images
			myTimer.reset();
			std::vector<unsigned char> inliers;
			cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC, 5.0);
			double time = myTimer.read();
			std::cout << "It took " << time << " when threshold is 5 " << std::endl;

			cv::Mat mosaic = garden6.clone();
			cv::warpPerspective(garden7, mosaic, H, mosaic.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

			cv::imshow("Mosiac 5", mosaic);
			cv::waitKey();
			
		}else if(i==7){
			std::cout << "\n-------------------------------------------------------" << std::endl;
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden6, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden7, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;
			for(const auto& match : matches) {
				if(match[0].distance < 0.8 * match[1].distance){
					goodMatches.push_back(match[0]);
					goodPts1.push_back(keypoints[match[0].queryIdx].pt);
					goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
				}
			}

			double elapsedTime = myTimer.read();
			totalMatches += goodMatches.size();
			totalTime += elapsedTime;

			//Homography between the two images
			myTimer.reset();
			std::vector<unsigned char> inliers;
			cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC, 6.0);
			double time = myTimer.read();
			std::cout << "It took " << time << " when threshold is 6 " << std::endl;

			cv::Mat mosaic = garden6.clone();
			cv::warpPerspective(garden7, mosaic, H, mosaic.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

			cv::imshow("Mosiac 6", mosaic);
			cv::waitKey();
			
		}else{
			std::cout << "\n-------------------------------------------------------" << std::endl;
			//Detect features in image using SIFT
			cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints;
			cv::Mat descriptors;
			detector->detectAndCompute(garden6, cv::noArray(), keypoints, descriptors);
			totalFeatures += keypoints.size();

			//Detect features in image 2 using SIFT
			cv::Ptr<cv::FeatureDetector> detector2 = cv::SIFT::create();
			std::vector<cv::KeyPoint> keypoints2;
			cv::Mat descriptors2;
			detector2->detectAndCompute(garden7, cv::noArray(), keypoints2, descriptors2);
			totalFeatures += keypoints2.size();

			//Vectors to hold the goodPoints
			std::vector<cv::Point2f> goodPts1, goodPts2;

			//Match the features in both images
			myTimer.reset();
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::FlannBasedMatcher::create();
			std::vector<std::vector<cv::DMatch>> matches;
			matcher->knnMatch(descriptors, descriptors2, matches, 2);
			std::vector<cv::DMatch> goodMatches;
			for(const auto& match : matches) {
				if(match[0].distance < 0.8 * match[1].distance){
					goodMatches.push_back(match[0]);
					goodPts1.push_back(keypoints[match[0].queryIdx].pt);
					goodPts2.push_back(keypoints2[match[0].trainIdx].pt);
				}
			}

			double elapsedTime = myTimer.read();
			totalMatches += goodMatches.size();
			totalTime += elapsedTime;

			//Homography between the two images
			myTimer.reset();
			std::vector<unsigned char> inliers;
			cv::Mat H = cv::findHomography(goodPts2, goodPts1, inliers, cv::RANSAC, 7.0);
			double time = myTimer.read();
			std::cout << "It took " << time << " when threshold is 7 " << std::endl;

			cv::Mat mosaic = garden6.clone();
			cv::warpPerspective(garden7, mosaic, H, mosaic.size(), cv::INTER_NEAREST, cv::BORDER_TRANSPARENT);

			cv::imshow("Mosiac 7", mosaic);
			cv::waitKey();
		}
	}*/

	return 0;
}