# CMake entry point
CMAKE_MINIMUM_REQUIRED(VERSION "3.12")
project (COSC_Lab_OpenGL)



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


find_package(OpenGL REQUIRED)
find_package (GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	${GLM_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${GLFW_INCLUDE_DIRS}
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	${GLEW_LIBRARIES}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# OpenGL Part 1
add_executable(Part01
	Part01/simpleWindow.cpp
)
target_link_libraries(Part01
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(Part01 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Part01/")
#create_target_launcher(Part01 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Part01/")
#create_default_target_launcher(Part01 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Part01/")

# OpenGL Lab 2
add_executable(Part02
	Part02/redTriangle.cpp
	common/Shader.cpp
	common/Shader.hpp
	common/Camera.hpp
    common/Camera.cpp
    common/Scene.hpp
    common/Scene.cpp
    common/Object.hpp
    common/Object.cpp
    common/Triangle.hpp
    common/Triangle.cpp
	Part02/basicShader.frag
	Part02/basicShader.vert

)
target_link_libraries(Part02
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(Part02 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Part02/")
#create_target_launcher(Part02 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Part02/")


SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET Part01 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Part01${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/Part01/"
)
add_custom_command(
   TARGET Part02 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Part02${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/Part02/"
)




elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
