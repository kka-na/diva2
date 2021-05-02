# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/diva2/diva2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diva2/diva2/build

# Include any dependencies generated for this target.
include test/sensing_proto/CMakeFiles/sensing_proto.dir/depend.make

# Include the progress variables for this target.
include test/sensing_proto/CMakeFiles/sensing_proto.dir/progress.make

# Include the compile flags for this target's objects.
include test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make

test/sensing_proto/sensors.pb.cc: ../test/protobuf/sensors.proto
test/sensing_proto/sensors.pb.cc: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on ../protobuf/sensors.proto"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/local/bin/protoc --cpp_out=/home/diva2/diva2/build/test/sensing_proto -I /home/diva2/diva2/test/protobuf /home/diva2/diva2/test/protobuf/sensors.proto

test/sensing_proto/sensors.pb.h: test/sensing_proto/sensors.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate test/sensing_proto/sensors.pb.h

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o: test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make
test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o: ../test/sensing_proto/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sensing_proto.dir/main.cpp.o -c /home/diva2/diva2/test/sensing_proto/main.cpp

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sensing_proto.dir/main.cpp.i"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sensing_proto/main.cpp > CMakeFiles/sensing_proto.dir/main.cpp.i

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sensing_proto.dir/main.cpp.s"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sensing_proto/main.cpp -o CMakeFiles/sensing_proto.dir/main.cpp.s

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.requires:

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.provides: test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.requires
	$(MAKE) -f test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.provides.build
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.provides

test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.provides.build: test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o


test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o: test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make
test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o: ../test/sensing_proto/GpsSensing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o -c /home/diva2/diva2/test/sensing_proto/GpsSensing.cpp

test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sensing_proto.dir/GpsSensing.cpp.i"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sensing_proto/GpsSensing.cpp > CMakeFiles/sensing_proto.dir/GpsSensing.cpp.i

test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sensing_proto.dir/GpsSensing.cpp.s"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sensing_proto/GpsSensing.cpp -o CMakeFiles/sensing_proto.dir/GpsSensing.cpp.s

test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.requires:

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.provides: test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.requires
	$(MAKE) -f test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.provides.build
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.provides

test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.provides.build: test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o


test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o: test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make
test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o: ../test/sensing_proto/CamSensing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sensing_proto.dir/CamSensing.cpp.o -c /home/diva2/diva2/test/sensing_proto/CamSensing.cpp

test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sensing_proto.dir/CamSensing.cpp.i"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sensing_proto/CamSensing.cpp > CMakeFiles/sensing_proto.dir/CamSensing.cpp.i

test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sensing_proto.dir/CamSensing.cpp.s"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sensing_proto/CamSensing.cpp -o CMakeFiles/sensing_proto.dir/CamSensing.cpp.s

test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.requires:

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.provides: test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.requires
	$(MAKE) -f test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.provides.build
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.provides

test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.provides.build: test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o


test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o: test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make
test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o: ../test/sensing_proto/CanSensingThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o -c /home/diva2/diva2/test/sensing_proto/CanSensingThread.cpp

test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.i"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sensing_proto/CanSensingThread.cpp > CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.i

test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.s"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sensing_proto/CanSensingThread.cpp -o CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.s

test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.requires:

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.provides: test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.requires
	$(MAKE) -f test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.provides.build
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.provides

test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.provides.build: test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o


test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o: test/sensing_proto/CMakeFiles/sensing_proto.dir/flags.make
test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o: test/sensing_proto/sensors.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sensing_proto.dir/sensors.pb.cc.o -c /home/diva2/diva2/build/test/sensing_proto/sensors.pb.cc

test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sensing_proto.dir/sensors.pb.cc.i"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/build/test/sensing_proto/sensors.pb.cc > CMakeFiles/sensing_proto.dir/sensors.pb.cc.i

test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sensing_proto.dir/sensors.pb.cc.s"
	cd /home/diva2/diva2/build/test/sensing_proto && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/build/test/sensing_proto/sensors.pb.cc -o CMakeFiles/sensing_proto.dir/sensors.pb.cc.s

test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.requires:

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.provides: test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.requires
	$(MAKE) -f test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.provides.build
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.provides

test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.provides.build: test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o


# Object files for target sensing_proto
sensing_proto_OBJECTS = \
"CMakeFiles/sensing_proto.dir/main.cpp.o" \
"CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o" \
"CMakeFiles/sensing_proto.dir/CamSensing.cpp.o" \
"CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o" \
"CMakeFiles/sensing_proto.dir/sensors.pb.cc.o"

# External object files for target sensing_proto
sensing_proto_EXTERNAL_OBJECTS =

test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/build.make
test/sensing_proto/sensing_proto: /usr/local/lib/libzmq.so
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
test/sensing_proto/sensing_proto: /usr/local/lib/libprotobuf.so
test/sensing_proto/sensing_proto: /usr/share/c++-mscl/libmscl.so
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
test/sensing_proto/sensing_proto: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
test/sensing_proto/sensing_proto: test/sensing_proto/CMakeFiles/sensing_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable sensing_proto"
	cd /home/diva2/diva2/build/test/sensing_proto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sensing_proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/sensing_proto/CMakeFiles/sensing_proto.dir/build: test/sensing_proto/sensing_proto

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/build

test/sensing_proto/CMakeFiles/sensing_proto.dir/requires: test/sensing_proto/CMakeFiles/sensing_proto.dir/main.cpp.o.requires
test/sensing_proto/CMakeFiles/sensing_proto.dir/requires: test/sensing_proto/CMakeFiles/sensing_proto.dir/GpsSensing.cpp.o.requires
test/sensing_proto/CMakeFiles/sensing_proto.dir/requires: test/sensing_proto/CMakeFiles/sensing_proto.dir/CamSensing.cpp.o.requires
test/sensing_proto/CMakeFiles/sensing_proto.dir/requires: test/sensing_proto/CMakeFiles/sensing_proto.dir/CanSensingThread.cpp.o.requires
test/sensing_proto/CMakeFiles/sensing_proto.dir/requires: test/sensing_proto/CMakeFiles/sensing_proto.dir/sensors.pb.cc.o.requires

.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/requires

test/sensing_proto/CMakeFiles/sensing_proto.dir/clean:
	cd /home/diva2/diva2/build/test/sensing_proto && $(CMAKE_COMMAND) -P CMakeFiles/sensing_proto.dir/cmake_clean.cmake
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/clean

test/sensing_proto/CMakeFiles/sensing_proto.dir/depend: test/sensing_proto/sensors.pb.cc
test/sensing_proto/CMakeFiles/sensing_proto.dir/depend: test/sensing_proto/sensors.pb.h
	cd /home/diva2/diva2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diva2/diva2 /home/diva2/diva2/test/sensing_proto /home/diva2/diva2/build /home/diva2/diva2/build/test/sensing_proto /home/diva2/diva2/build/test/sensing_proto/CMakeFiles/sensing_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/sensing_proto/CMakeFiles/sensing_proto.dir/depend

