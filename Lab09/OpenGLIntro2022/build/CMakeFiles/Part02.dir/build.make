# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build

# Include any dependencies generated for this target.
include CMakeFiles/Part02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Part02.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Part02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part02.dir/flags.make

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o: ../Part02/redTriangle.cpp
CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o -MF CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.d -o CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/Part02/redTriangle.cpp

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/Part02/redTriangle.cpp > CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/Part02/redTriangle.cpp -o CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s

CMakeFiles/Part02.dir/common/Shader.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Shader.cpp.o: ../common/Shader.cpp
CMakeFiles/Part02.dir/common/Shader.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Part02.dir/common/Shader.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/common/Shader.cpp.o -MF CMakeFiles/Part02.dir/common/Shader.cpp.o.d -o CMakeFiles/Part02.dir/common/Shader.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Shader.cpp

CMakeFiles/Part02.dir/common/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Shader.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Shader.cpp > CMakeFiles/Part02.dir/common/Shader.cpp.i

CMakeFiles/Part02.dir/common/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Shader.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Shader.cpp -o CMakeFiles/Part02.dir/common/Shader.cpp.s

CMakeFiles/Part02.dir/common/Camera.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Camera.cpp.o: ../common/Camera.cpp
CMakeFiles/Part02.dir/common/Camera.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Part02.dir/common/Camera.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/common/Camera.cpp.o -MF CMakeFiles/Part02.dir/common/Camera.cpp.o.d -o CMakeFiles/Part02.dir/common/Camera.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Camera.cpp

CMakeFiles/Part02.dir/common/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Camera.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Camera.cpp > CMakeFiles/Part02.dir/common/Camera.cpp.i

CMakeFiles/Part02.dir/common/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Camera.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Camera.cpp -o CMakeFiles/Part02.dir/common/Camera.cpp.s

CMakeFiles/Part02.dir/common/Scene.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Scene.cpp.o: ../common/Scene.cpp
CMakeFiles/Part02.dir/common/Scene.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Part02.dir/common/Scene.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/common/Scene.cpp.o -MF CMakeFiles/Part02.dir/common/Scene.cpp.o.d -o CMakeFiles/Part02.dir/common/Scene.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Scene.cpp

CMakeFiles/Part02.dir/common/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Scene.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Scene.cpp > CMakeFiles/Part02.dir/common/Scene.cpp.i

CMakeFiles/Part02.dir/common/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Scene.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Scene.cpp -o CMakeFiles/Part02.dir/common/Scene.cpp.s

CMakeFiles/Part02.dir/common/Object.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Object.cpp.o: ../common/Object.cpp
CMakeFiles/Part02.dir/common/Object.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Part02.dir/common/Object.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/common/Object.cpp.o -MF CMakeFiles/Part02.dir/common/Object.cpp.o.d -o CMakeFiles/Part02.dir/common/Object.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Object.cpp

CMakeFiles/Part02.dir/common/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Object.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Object.cpp > CMakeFiles/Part02.dir/common/Object.cpp.i

CMakeFiles/Part02.dir/common/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Object.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Object.cpp -o CMakeFiles/Part02.dir/common/Object.cpp.s

CMakeFiles/Part02.dir/common/Triangle.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Triangle.cpp.o: ../common/Triangle.cpp
CMakeFiles/Part02.dir/common/Triangle.cpp.o: CMakeFiles/Part02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Part02.dir/common/Triangle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Part02.dir/common/Triangle.cpp.o -MF CMakeFiles/Part02.dir/common/Triangle.cpp.o.d -o CMakeFiles/Part02.dir/common/Triangle.cpp.o -c /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Triangle.cpp

CMakeFiles/Part02.dir/common/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Triangle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Triangle.cpp > CMakeFiles/Part02.dir/common/Triangle.cpp.i

CMakeFiles/Part02.dir/common/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Triangle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/common/Triangle.cpp -o CMakeFiles/Part02.dir/common/Triangle.cpp.s

# Object files for target Part02
Part02_OBJECTS = \
"CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o" \
"CMakeFiles/Part02.dir/common/Shader.cpp.o" \
"CMakeFiles/Part02.dir/common/Camera.cpp.o" \
"CMakeFiles/Part02.dir/common/Scene.cpp.o" \
"CMakeFiles/Part02.dir/common/Object.cpp.o" \
"CMakeFiles/Part02.dir/common/Triangle.cpp.o"

# External object files for target Part02
Part02_EXTERNAL_OBJECTS =

Part02: CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o
Part02: CMakeFiles/Part02.dir/common/Shader.cpp.o
Part02: CMakeFiles/Part02.dir/common/Camera.cpp.o
Part02: CMakeFiles/Part02.dir/common/Scene.cpp.o
Part02: CMakeFiles/Part02.dir/common/Object.cpp.o
Part02: CMakeFiles/Part02.dir/common/Triangle.cpp.o
Part02: CMakeFiles/Part02.dir/build.make
Part02: /usr/local/lib/libglfw.3.3.dylib
Part02: CMakeFiles/Part02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Part02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Part02.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/Cellar/cmake/3.22.3/bin/cmake -E copy /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/./Part02 /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/Part02/

# Rule to build all files generated by this target.
CMakeFiles/Part02.dir/build: Part02
.PHONY : CMakeFiles/Part02.dir/build

CMakeFiles/Part02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Part02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Part02.dir/clean

CMakeFiles/Part02.dir/depend:
	cd /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022 /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022 /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build /Users/shaystevens/Desktop/COSC342/Lab09/OpenGLIntro2022/build/CMakeFiles/Part02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Part02.dir/depend
