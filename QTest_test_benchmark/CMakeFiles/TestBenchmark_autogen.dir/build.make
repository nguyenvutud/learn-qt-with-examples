# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vunguyen/QT_workspace/QTest_test_benchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vunguyen/QT_workspace/QTest_test_benchmark

# Utility rule file for TestBenchmark_autogen.

# Include the progress variables for this target.
include CMakeFiles/TestBenchmark_autogen.dir/progress.make

CMakeFiles/TestBenchmark_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vunguyen/QT_workspace/QTest_test_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target TestBenchmark"
	/usr/bin/cmake -E cmake_autogen /home/vunguyen/QT_workspace/QTest_test_benchmark/CMakeFiles/TestBenchmark_autogen.dir/AutogenInfo.json ""

TestBenchmark_autogen: CMakeFiles/TestBenchmark_autogen
TestBenchmark_autogen: CMakeFiles/TestBenchmark_autogen.dir/build.make

.PHONY : TestBenchmark_autogen

# Rule to build all files generated by this target.
CMakeFiles/TestBenchmark_autogen.dir/build: TestBenchmark_autogen

.PHONY : CMakeFiles/TestBenchmark_autogen.dir/build

CMakeFiles/TestBenchmark_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestBenchmark_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestBenchmark_autogen.dir/clean

CMakeFiles/TestBenchmark_autogen.dir/depend:
	cd /home/vunguyen/QT_workspace/QTest_test_benchmark && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vunguyen/QT_workspace/QTest_test_benchmark /home/vunguyen/QT_workspace/QTest_test_benchmark /home/vunguyen/QT_workspace/QTest_test_benchmark /home/vunguyen/QT_workspace/QTest_test_benchmark /home/vunguyen/QT_workspace/QTest_test_benchmark/CMakeFiles/TestBenchmark_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestBenchmark_autogen.dir/depend
