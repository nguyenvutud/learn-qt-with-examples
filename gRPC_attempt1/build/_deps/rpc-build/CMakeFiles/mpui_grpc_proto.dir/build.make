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
CMAKE_SOURCE_DIR = /home/vunguyen/QT_workspace/gRPC_attempt1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vunguyen/QT_workspace/gRPC_attempt1/build

# Include any dependencies generated for this target.
include _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend.make

# Include the progress variables for this target.
include _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/flags.make

_deps/rpc-build/MPUInterface.pb.cc: _deps/rpc-src/doc/MPUInterface.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vunguyen/QT_workspace/gRPC_attempt1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating MPUInterface.pb.cc, MPUInterface.pb.h, MPUInterface.grpc.pb.cc, MPUInterface.grpc.pb.h"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/local/bin/protoc-3.19.4.0 --grpc_out /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build --cpp_out /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build -I /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src/doc --plugin=protoc-gen-grpc="/home/vunguyen/.local/bin/grpc_cpp_plugin" /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src/doc/MPUInterface.proto

_deps/rpc-build/MPUInterface.pb.h: _deps/rpc-build/MPUInterface.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/rpc-build/MPUInterface.pb.h

_deps/rpc-build/MPUInterface.grpc.pb.cc: _deps/rpc-build/MPUInterface.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/rpc-build/MPUInterface.grpc.pb.cc

_deps/rpc-build/MPUInterface.grpc.pb.h: _deps/rpc-build/MPUInterface.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/rpc-build/MPUInterface.grpc.pb.h

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/flags.make
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o: _deps/rpc-build/MPUInterface.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vunguyen/QT_workspace/gRPC_attempt1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o -c /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.grpc.pb.cc

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.i"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.grpc.pb.cc > CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.i

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.s"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.grpc.pb.cc -o CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.s

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/flags.make
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o: _deps/rpc-build/MPUInterface.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vunguyen/QT_workspace/gRPC_attempt1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o -c /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.pb.cc

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.i"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.pb.cc > CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.i

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.s"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.pb.cc -o CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.s

# Object files for target mpui_grpc_proto
mpui_grpc_proto_OBJECTS = \
"CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o" \
"CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o"

# External object files for target mpui_grpc_proto
mpui_grpc_proto_EXTERNAL_OBJECTS =

_deps/rpc-build/libmpui_grpc_proto.so: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.grpc.pb.cc.o
_deps/rpc-build/libmpui_grpc_proto.so: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/MPUInterface.pb.cc.o
_deps/rpc-build/libmpui_grpc_proto.so: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/build.make
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libgrpc++_reflection.so.1.47.0
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libgrpc++.so.1.47.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libprotobuf.so.3.19.4.0
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libgrpc.so.25.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libz.so
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libcares.a
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libaddress_sorting.so.25.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libre2.so.9.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_raw_hash_set.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_hashtablez_sampler.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_hash.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_city.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_low_level_hash.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_statusor.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_bad_variant_access.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libgpr.so.25.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /home/vunguyen/.local/lib/libupb.so.25.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_status.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_distributions.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_seed_sequences.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_pool_urbg.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_randen.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_randen_hwaes.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_randen_hwaes_impl.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_randen_slow.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_platform.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_internal_seed_material.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_random_seed_gen_exception.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_cord.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_bad_optional_access.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_cordz_info.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_cord_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_cordz_functions.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_exponential_biased.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_cordz_handle.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_str_format_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_synchronization.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_stacktrace.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_symbolize.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_debugging_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_demangle_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_graphcycles_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_malloc_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_time.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_strings.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_throw_delegate.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_int128.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_strings_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_base.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_spinlock_wait.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_raw_logging_internal.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_log_severity.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_civil_time.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/local/lib/libabsl_time_zone.so.2111.0.0
_deps/rpc-build/libmpui_grpc_proto.so: /usr/lib/x86_64-linux-gnu/libssl.so
_deps/rpc-build/libmpui_grpc_proto.so: /usr/lib/x86_64-linux-gnu/libcrypto.so
_deps/rpc-build/libmpui_grpc_proto.so: _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vunguyen/QT_workspace/gRPC_attempt1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libmpui_grpc_proto.so"
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mpui_grpc_proto.dir/link.txt --verbose=$(VERBOSE)
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && cp -r /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/libmpui_grpc_proto.so /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src/lib/libnew/
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && cp -r /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.grpc.pb.h /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src/include/
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && cp -r /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/MPUInterface.pb.h /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src/include/

# Rule to build all files generated by this target.
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/build: _deps/rpc-build/libmpui_grpc_proto.so

.PHONY : _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/build

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/clean:
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build && $(CMAKE_COMMAND) -P CMakeFiles/mpui_grpc_proto.dir/cmake_clean.cmake
.PHONY : _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/clean

_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend: _deps/rpc-build/MPUInterface.pb.cc
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend: _deps/rpc-build/MPUInterface.pb.h
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend: _deps/rpc-build/MPUInterface.grpc.pb.cc
_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend: _deps/rpc-build/MPUInterface.grpc.pb.h
	cd /home/vunguyen/QT_workspace/gRPC_attempt1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vunguyen/QT_workspace/gRPC_attempt1 /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src /home/vunguyen/QT_workspace/gRPC_attempt1/build /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build /home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/rpc-build/CMakeFiles/mpui_grpc_proto.dir/depend

