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
CMAKE_SOURCE_DIR = /home/vunguyen/QT_workspace/QTest_replay_Gui_event

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vunguyen/QT_workspace/QTest_replay_Gui_event

# Include any dependencies generated for this target.
include CMakeFiles/replaying_event.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/replaying_event.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/replaying_event.dir/flags.make

CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o: CMakeFiles/replaying_event.dir/flags.make
CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o: replaying_event_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vunguyen/QT_workspace/QTest_replay_Gui_event/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o -c /home/vunguyen/QT_workspace/QTest_replay_Gui_event/replaying_event_autogen/mocs_compilation.cpp

CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vunguyen/QT_workspace/QTest_replay_Gui_event/replaying_event_autogen/mocs_compilation.cpp > CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.i

CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vunguyen/QT_workspace/QTest_replay_Gui_event/replaying_event_autogen/mocs_compilation.cpp -o CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.s

CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o: CMakeFiles/replaying_event.dir/flags.make
CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o: tst_replaying_event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vunguyen/QT_workspace/QTest_replay_Gui_event/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o -c /home/vunguyen/QT_workspace/QTest_replay_Gui_event/tst_replaying_event.cpp

CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vunguyen/QT_workspace/QTest_replay_Gui_event/tst_replaying_event.cpp > CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.i

CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vunguyen/QT_workspace/QTest_replay_Gui_event/tst_replaying_event.cpp -o CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.s

# Object files for target replaying_event
replaying_event_OBJECTS = \
"CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o"

# External object files for target replaying_event
replaying_event_EXTERNAL_OBJECTS =

replaying_event: CMakeFiles/replaying_event.dir/replaying_event_autogen/mocs_compilation.cpp.o
replaying_event: CMakeFiles/replaying_event.dir/tst_replaying_event.cpp.o
replaying_event: CMakeFiles/replaying_event.dir/build.make
replaying_event: /usr/lib/x86_64-linux-gnu/libQt5Test.so.5.12.8
replaying_event: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
replaying_event: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
replaying_event: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
replaying_event: CMakeFiles/replaying_event.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vunguyen/QT_workspace/QTest_replay_Gui_event/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable replaying_event"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/replaying_event.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/replaying_event.dir/build: replaying_event

.PHONY : CMakeFiles/replaying_event.dir/build

CMakeFiles/replaying_event.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/replaying_event.dir/cmake_clean.cmake
.PHONY : CMakeFiles/replaying_event.dir/clean

CMakeFiles/replaying_event.dir/depend:
	cd /home/vunguyen/QT_workspace/QTest_replay_Gui_event && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vunguyen/QT_workspace/QTest_replay_Gui_event /home/vunguyen/QT_workspace/QTest_replay_Gui_event /home/vunguyen/QT_workspace/QTest_replay_Gui_event /home/vunguyen/QT_workspace/QTest_replay_Gui_event /home/vunguyen/QT_workspace/QTest_replay_Gui_event/CMakeFiles/replaying_event.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/replaying_event.dir/depend

