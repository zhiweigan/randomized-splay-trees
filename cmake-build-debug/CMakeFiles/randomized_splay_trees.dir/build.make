# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhiweigan/Documents/randomized-splay-trees

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/randomized_splay_trees.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/randomized_splay_trees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/randomized_splay_trees.dir/flags.make

CMakeFiles/randomized_splay_trees.dir/main.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/randomized_splay_trees.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/main.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/main.cpp

CMakeFiles/randomized_splay_trees.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/main.cpp > CMakeFiles/randomized_splay_trees.dir/main.cpp.i

CMakeFiles/randomized_splay_trees.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/main.cpp -o CMakeFiles/randomized_splay_trees.dir/main.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o: ../trees/vanilla.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/vanilla.cpp

CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/vanilla.cpp > CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/vanilla.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o: ../trees/template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/template.cpp

CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/template.cpp > CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/template.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.s

CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o: ../tests/random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/tests/random.cpp

CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/tests/random.cpp > CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.i

CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/tests/random.cpp -o CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.s

CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o: ../tests/tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/tests/tester.cpp

CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/tests/tester.cpp > CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.i

CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/tests/tester.cpp -o CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.s

CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o: ../tests/zipf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/tests/zipf.cpp

CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/tests/zipf.cpp > CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.i

CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/tests/zipf.cpp -o CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o: ../trees/scheme1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme1.cpp

CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme1.cpp > CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme1.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o: ../trees/scheme2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme2.cpp

CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme2.cpp > CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/scheme2.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o: ../trees/regularBST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/regularBST.cpp

CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/regularBST.cpp > CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/regularBST.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.s

CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o: ../tests/justone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/tests/justone.cpp

CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/tests/justone.cpp > CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.i

CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/tests/justone.cpp -o CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.s

CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o: ../trees/threeRotScheme.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/trees/threeRotScheme.cpp

CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/trees/threeRotScheme.cpp > CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.i

CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/trees/threeRotScheme.cpp -o CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.s

CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o: CMakeFiles/randomized_splay_trees.dir/flags.make
CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o: ../tests/splayline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o -c /Users/zhiweigan/Documents/randomized-splay-trees/tests/splayline.cpp

CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiweigan/Documents/randomized-splay-trees/tests/splayline.cpp > CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.i

CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiweigan/Documents/randomized-splay-trees/tests/splayline.cpp -o CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.s

# Object files for target randomized_splay_trees
randomized_splay_trees_OBJECTS = \
"CMakeFiles/randomized_splay_trees.dir/main.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o" \
"CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o"

# External object files for target randomized_splay_trees
randomized_splay_trees_EXTERNAL_OBJECTS =

randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/main.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/vanilla.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/template.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/tests/random.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/tests/tester.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/tests/zipf.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/scheme1.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/scheme2.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/regularBST.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/tests/justone.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/trees/threeRotScheme.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/tests/splayline.cpp.o
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/build.make
randomized_splay_trees: CMakeFiles/randomized_splay_trees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable randomized_splay_trees"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/randomized_splay_trees.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/randomized_splay_trees.dir/build: randomized_splay_trees

.PHONY : CMakeFiles/randomized_splay_trees.dir/build

CMakeFiles/randomized_splay_trees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/randomized_splay_trees.dir/cmake_clean.cmake
.PHONY : CMakeFiles/randomized_splay_trees.dir/clean

CMakeFiles/randomized_splay_trees.dir/depend:
	cd /Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhiweigan/Documents/randomized-splay-trees /Users/zhiweigan/Documents/randomized-splay-trees /Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug /Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug /Users/zhiweigan/Documents/randomized-splay-trees/cmake-build-debug/CMakeFiles/randomized_splay_trees.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/randomized_splay_trees.dir/depend

