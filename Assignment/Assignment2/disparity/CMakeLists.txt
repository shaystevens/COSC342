CMAKE_MINIMUM_REQUIRED(VERSION "3.12")

set(CMAKE_CXX_STANDARD 14)

project(Stereo)
set(OpenCV_DIR "/usr/local/opt/opencv/")
#find_package(OpenCV REQUIRED)
include_directories("/usr/local/opt/opencv/include/opencv4/")
link_directories("/usr/local/opt/opencv/lib/")
add_executable(disparity disparity.cpp CalibrationIO.h CalibrationIO.cpp Timer.h Timer.cpp)
target_link_libraries(disparity
  libopencv_core.dylib 
  libopencv_highgui.dylib
  libopencv_imgcodecs.dylib 
  libopencv_features2d.dylib
  libopencv_xfeatures2d.dylib
  libopencv_imgproc.dylib
  libopencv_calib3d.dylib
) 