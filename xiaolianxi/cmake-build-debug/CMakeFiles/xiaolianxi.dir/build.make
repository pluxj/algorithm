# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zengzhiyong/算法/xiaolianxi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xiaolianxi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xiaolianxi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xiaolianxi.dir/flags.make

CMakeFiles/xiaolianxi.dir/main.cpp.o: CMakeFiles/xiaolianxi.dir/flags.make
CMakeFiles/xiaolianxi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xiaolianxi.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xiaolianxi.dir/main.cpp.o -c /Users/zengzhiyong/算法/xiaolianxi/main.cpp

CMakeFiles/xiaolianxi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xiaolianxi.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zengzhiyong/算法/xiaolianxi/main.cpp > CMakeFiles/xiaolianxi.dir/main.cpp.i

CMakeFiles/xiaolianxi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xiaolianxi.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zengzhiyong/算法/xiaolianxi/main.cpp -o CMakeFiles/xiaolianxi.dir/main.cpp.s

CMakeFiles/xiaolianxi.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/xiaolianxi.dir/main.cpp.o.requires

CMakeFiles/xiaolianxi.dir/main.cpp.o.provides: CMakeFiles/xiaolianxi.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/xiaolianxi.dir/build.make CMakeFiles/xiaolianxi.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/xiaolianxi.dir/main.cpp.o.provides

CMakeFiles/xiaolianxi.dir/main.cpp.o.provides.build: CMakeFiles/xiaolianxi.dir/main.cpp.o


# Object files for target xiaolianxi
xiaolianxi_OBJECTS = \
"CMakeFiles/xiaolianxi.dir/main.cpp.o"

# External object files for target xiaolianxi
xiaolianxi_EXTERNAL_OBJECTS =

xiaolianxi: CMakeFiles/xiaolianxi.dir/main.cpp.o
xiaolianxi: CMakeFiles/xiaolianxi.dir/build.make
xiaolianxi: CMakeFiles/xiaolianxi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xiaolianxi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xiaolianxi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xiaolianxi.dir/build: xiaolianxi

.PHONY : CMakeFiles/xiaolianxi.dir/build

CMakeFiles/xiaolianxi.dir/requires: CMakeFiles/xiaolianxi.dir/main.cpp.o.requires

.PHONY : CMakeFiles/xiaolianxi.dir/requires

CMakeFiles/xiaolianxi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xiaolianxi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xiaolianxi.dir/clean

CMakeFiles/xiaolianxi.dir/depend:
	cd /Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zengzhiyong/算法/xiaolianxi /Users/zengzhiyong/算法/xiaolianxi /Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug /Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug /Users/zengzhiyong/算法/xiaolianxi/cmake-build-debug/CMakeFiles/xiaolianxi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xiaolianxi.dir/depend

