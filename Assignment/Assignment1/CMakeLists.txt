CMAKE_MINIMUM_REQUIRED(VERSION "3.12")

set(CMAKE_CXX_STANDARD 14)

project(Features)

find_package (OpenCV CONFIG REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

#link_directories("/usr/local/opt/opencv/lib/")
add_executable(features featureMatching.cpp Timer.h Timer.cpp)
target_link_libraries(features 
  ${OpenCV_LIBS}
)