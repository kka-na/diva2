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
include test/sender_toCloud/CMakeFiles/senderTocloud.dir/depend.make

# Include the progress variables for this target.
include test/sender_toCloud/CMakeFiles/senderTocloud.dir/progress.make

# Include the compile flags for this target's objects.
include test/sender_toCloud/CMakeFiles/senderTocloud.dir/flags.make

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o: test/sender_toCloud/CMakeFiles/senderTocloud.dir/flags.make
test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o: ../test/sender_toCloud/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/senderTocloud.dir/main.cpp.o -c /home/diva2/diva2/test/sender_toCloud/main.cpp

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/senderTocloud.dir/main.cpp.i"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sender_toCloud/main.cpp > CMakeFiles/senderTocloud.dir/main.cpp.i

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/senderTocloud.dir/main.cpp.s"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sender_toCloud/main.cpp -o CMakeFiles/senderTocloud.dir/main.cpp.s

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.requires:

.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.requires

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.provides: test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.requires
	$(MAKE) -f test/sender_toCloud/CMakeFiles/senderTocloud.dir/build.make test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.provides.build
.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.provides

test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.provides.build: test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o


test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o: test/sender_toCloud/CMakeFiles/senderTocloud.dir/flags.make
test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o: ../test/sender_toCloud/GpsSenderThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o -c /home/diva2/diva2/test/sender_toCloud/GpsSenderThread.cpp

test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.i"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sender_toCloud/GpsSenderThread.cpp > CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.i

test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.s"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sender_toCloud/GpsSenderThread.cpp -o CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.s

test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.requires:

.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.requires

test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.provides: test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.requires
	$(MAKE) -f test/sender_toCloud/CMakeFiles/senderTocloud.dir/build.make test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.provides.build
.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.provides

test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.provides.build: test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o


test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o: test/sender_toCloud/CMakeFiles/senderTocloud.dir/flags.make
test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o: ../test/sender_toCloud/ImuSenderThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o -c /home/diva2/diva2/test/sender_toCloud/ImuSenderThread.cpp

test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.i"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/test/sender_toCloud/ImuSenderThread.cpp > CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.i

test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.s"
	cd /home/diva2/diva2/build/test/sender_toCloud && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/test/sender_toCloud/ImuSenderThread.cpp -o CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.s

test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.requires:

.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.requires

test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.provides: test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.requires
	$(MAKE) -f test/sender_toCloud/CMakeFiles/senderTocloud.dir/build.make test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.provides.build
.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.provides

test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.provides.build: test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o


# Object files for target senderTocloud
senderTocloud_OBJECTS = \
"CMakeFiles/senderTocloud.dir/main.cpp.o" \
"CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o" \
"CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o"

# External object files for target senderTocloud
senderTocloud_EXTERNAL_OBJECTS =

test/sender_toCloud/senderTocloud: test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o
test/sender_toCloud/senderTocloud: test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o
test/sender_toCloud/senderTocloud: test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o
test/sender_toCloud/senderTocloud: test/sender_toCloud/CMakeFiles/senderTocloud.dir/build.make
test/sender_toCloud/senderTocloud: /usr/local/lib/libzmq.so
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/share/c++-mscl/libmscl.so
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
test/sender_toCloud/senderTocloud: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
test/sender_toCloud/senderTocloud: test/sender_toCloud/CMakeFiles/senderTocloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diva2/diva2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable senderTocloud"
	cd /home/diva2/diva2/build/test/sender_toCloud && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/senderTocloud.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/sender_toCloud/CMakeFiles/senderTocloud.dir/build: test/sender_toCloud/senderTocloud

.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/build

test/sender_toCloud/CMakeFiles/senderTocloud.dir/requires: test/sender_toCloud/CMakeFiles/senderTocloud.dir/main.cpp.o.requires
test/sender_toCloud/CMakeFiles/senderTocloud.dir/requires: test/sender_toCloud/CMakeFiles/senderTocloud.dir/GpsSenderThread.cpp.o.requires
test/sender_toCloud/CMakeFiles/senderTocloud.dir/requires: test/sender_toCloud/CMakeFiles/senderTocloud.dir/ImuSenderThread.cpp.o.requires

.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/requires

test/sender_toCloud/CMakeFiles/senderTocloud.dir/clean:
	cd /home/diva2/diva2/build/test/sender_toCloud && $(CMAKE_COMMAND) -P CMakeFiles/senderTocloud.dir/cmake_clean.cmake
.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/clean

test/sender_toCloud/CMakeFiles/senderTocloud.dir/depend:
	cd /home/diva2/diva2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diva2/diva2 /home/diva2/diva2/test/sender_toCloud /home/diva2/diva2/build /home/diva2/diva2/build/test/sender_toCloud /home/diva2/diva2/build/test/sender_toCloud/CMakeFiles/senderTocloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/sender_toCloud/CMakeFiles/senderTocloud.dir/depend

