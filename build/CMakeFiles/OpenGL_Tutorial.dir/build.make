# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rvolkov/Documents/projects/opengl_tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rvolkov/Documents/projects/opengl_tutorial/build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL_Tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGL_Tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_Tutorial.dir/flags.make

CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o: CMakeFiles/OpenGL_Tutorial.dir/flags.make
CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o: /Users/rvolkov/Documents/projects/opengl_tutorial/main.cpp
CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o: CMakeFiles/OpenGL_Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rvolkov/Documents/projects/opengl_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o -MF CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o.d -o CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o -c /Users/rvolkov/Documents/projects/opengl_tutorial/main.cpp

CMakeFiles/OpenGL_Tutorial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGL_Tutorial.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rvolkov/Documents/projects/opengl_tutorial/main.cpp > CMakeFiles/OpenGL_Tutorial.dir/main.cpp.i

CMakeFiles/OpenGL_Tutorial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Tutorial.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rvolkov/Documents/projects/opengl_tutorial/main.cpp -o CMakeFiles/OpenGL_Tutorial.dir/main.cpp.s

# Object files for target OpenGL_Tutorial
OpenGL_Tutorial_OBJECTS = \
"CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o"

# External object files for target OpenGL_Tutorial
OpenGL_Tutorial_EXTERNAL_OBJECTS =

OpenGL_Tutorial: CMakeFiles/OpenGL_Tutorial.dir/main.cpp.o
OpenGL_Tutorial: CMakeFiles/OpenGL_Tutorial.dir/build.make
OpenGL_Tutorial: CMakeFiles/OpenGL_Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/rvolkov/Documents/projects/opengl_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OpenGL_Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL_Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_Tutorial.dir/build: OpenGL_Tutorial
.PHONY : CMakeFiles/OpenGL_Tutorial.dir/build

CMakeFiles/OpenGL_Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL_Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_Tutorial.dir/clean

CMakeFiles/OpenGL_Tutorial.dir/depend:
	cd /Users/rvolkov/Documents/projects/opengl_tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rvolkov/Documents/projects/opengl_tutorial /Users/rvolkov/Documents/projects/opengl_tutorial /Users/rvolkov/Documents/projects/opengl_tutorial/build /Users/rvolkov/Documents/projects/opengl_tutorial/build /Users/rvolkov/Documents/projects/opengl_tutorial/build/CMakeFiles/OpenGL_Tutorial.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OpenGL_Tutorial.dir/depend

