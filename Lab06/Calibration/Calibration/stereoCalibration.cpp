#include <opencv2/opencv.hpp>
#include "CalibrationIO.h"

int main(int argc, char* argv[]) {

    cv::namedWindow("Left");
    cv::namedWindow("Right");

    char fname[255];
    /*for (int i = 457; i < 476; ++i) {
        sprintf(fname, "../../data/CalibrationLeft/DSCF%04d_L.JPG", i);
        cv::Mat imageL = cv::imread(fname);

        //Draw corners on left image
        std::vector<cv::Point2f> corners1, corners2;
        //pattern size x=10 y=5
        cv::Size patternSize(10,5);
        bool patternFound = cv::findChessboardCorners(imageL, patternSize, corners1);
        cv::drawChessboardCorners(imageL, patternSize, corners1, patternFound);

        cv::imshow("Left", imageL);
        cv::waitKey(10);

    
        sprintf(fname, "../../data/CalibrationRight/DSCF%04d_R.JPG", i);
        cv::Mat imageR = cv::imread(fname);

        //Draw corners on right image
        bool rightPatternFound = cv::findChessboardCorners(imageR, patternSize, corners2);
        cv::drawChessboardCorners(imageR, patternSize, corners2, rightPatternFound);

        cv::imshow("Right", imageR);
        cv::waitKey(100);
    }*/

    std::vector<std::vector<cv::Point3f>> objectPoints, objectPoints2;
    std::vector<std::vector<cv::Point2f>> imagePoints, imagePoints2;
    cv::Size imageSize(1920, 1080); // in pixels
    cv::Size patternSize(10, 5); // in squares
    cv::Mat K, K2;
    std::vector<double> distCoeffs, distCoeffs2;
    std::vector<cv::Mat> rvecs, tvecs, rvecs2, tvecs2;
    std::vector<cv::Point3f> checkerboardPattern;

    // Fill checkerboardPattern with the 3D corner locations
    for (int y = 0; y < patternSize.height; ++y) {
        for (int x = 0; x < patternSize.width; ++x) {
            // Add (x,y,0) to checkerboardPattern
            checkerboardPattern.push_back(cv::Point3f(x,y,0));
        }
    }

    //Left camera callibration and error
    for (int i = 457; i < 476; ++i) {
        sprintf(fname, "../../data/CalibrationLeft/DSCF%04d_L.JPG", i);
        cv::Mat image1 = cv::imread(fname);

        std::vector<cv::Point2f> corners1;

        bool patternFound = cv::findChessboardCorners(image1, patternSize, corners1);
        cv::drawChessboardCorners(image1, patternSize, corners1, patternFound);
        imagePoints.push_back(corners1);
        objectPoints.push_back(checkerboardPattern);
    }

    double err = cv::calibrateCamera(objectPoints, imagePoints, imageSize, K, distCoeffs, rvecs, tvecs);
    std::cout << "The error value for left camera is " << err << std::endl;

    //Right camera callibration and error
    for (int i = 457; i < 476; ++i) {
        sprintf(fname, "../../data/CalibrationRight/DSCF%04d_R.JPG", i);
        cv::Mat image2 = cv::imread(fname);

        std::vector<cv::Point2f> corners2;

        bool patternFound = cv::findChessboardCorners(image2, patternSize, corners2);
        cv::drawChessboardCorners(image2, patternSize, corners2, patternFound);
        imagePoints2.push_back(corners2);
        objectPoints2.push_back(checkerboardPattern);
    }

    double err2 = cv::calibrateCamera(objectPoints2, imagePoints2, imageSize, K2, distCoeffs2, rvecs2, tvecs2);
    std::cout << "The error value for right camera is " << err2 << std::endl;

    //Estimate stereo callibration
    cv::Mat R(3, 3, CV_64FC1);
    cv::Mat E(3, 3, CV_64FC1);
    cv::Mat T(3,1,CV_64FC1);
    cv::Mat F(3, 3, CV_64FC1);
    double stereoCallibration = cv::stereoCalibrate(objectPoints, imagePoints, imagePoints2, K, distCoeffs, K2, distCoeffs2, imageSize, R, T, E, F);

    std::cout << "The stereo callibration estimate is " << stereoCallibration << std::endl;

    std::cout << "Fundamental Matrix is " << F << std::endl;

    saveStereoCalibration("/Users/shaystevens/Desktop/COSC342/Lab06/Calibration/Calibration/stereoCalibration.txt", K, distCoeffs, K2, distCoeffs2, R, T);

    return 0;
}

