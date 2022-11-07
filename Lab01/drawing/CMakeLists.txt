CMAKE_MINIMUM_REQUIRED(VERSION "3.12")

set(CMAKE_CXX_STANDARD 14)

project(drawing)

#if you want to compile for arm64 uncomment the following 
#set(CMAKE_OSX_ARCHITECTURES arm64)
if(CMAKE_OSX_ARCHITECTURES STREQUAL arm64)
	message( "/opt/homebrew/")
	
	set(CMAKE_PREFIX_PATH "/opt/homebrew/"
    CACHE PATH "Path to Homebrew in./stallation")
else()
	message( "/usr/local")
	
	set(CMAKE_PREFIX_PATH "/usr/local"
    CACHE PATH "Path to Homebrew installation")

endif()

# include OpenCV
find_package (OpenCV CONFIG REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

#dont set this manually at home
#set(OpenCV_DIR "/usr/local/opt/opencv/")

add_executable(drawing drawing.cpp)

target_link_libraries(drawing ${OpenCV_LIBS}
 
)

