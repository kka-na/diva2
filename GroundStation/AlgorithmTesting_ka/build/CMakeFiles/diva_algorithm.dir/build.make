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
CMAKE_SOURCE_DIR = /home/diva2/diva2/GroundStation/AlgorithmTesting_ka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build

# Include any dependencies generated for this target.
include CMakeFiles/diva_algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/diva_algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/diva_algorithm.dir/flags.make

sensors.pb.cc: /home/diva2/diva2/protobuf/sensors.proto
sensors.pb.cc: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on ../../protobuf/sensors.proto"
	/usr/local/bin/protoc --cpp_out=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build -I /home/diva2/diva2/protobuf /home/diva2/diva2/protobuf/sensors.proto

sensors.pb.h: sensors.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate sensors.pb.h

CMakeFiles/diva_algorithm.dir/main.cpp.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/diva_algorithm.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/main.cpp.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/main.cpp

CMakeFiles/diva_algorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/main.cpp > CMakeFiles/diva_algorithm.dir/main.cpp.i

CMakeFiles/diva_algorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/main.cpp -o CMakeFiles/diva_algorithm.dir/main.cpp.s

CMakeFiles/diva_algorithm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/main.cpp.o.requires

CMakeFiles/diva_algorithm.dir/main.cpp.o.provides: CMakeFiles/diva_algorithm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/main.cpp.o.provides

CMakeFiles/diva_algorithm.dir/main.cpp.o.provides.build: CMakeFiles/diva_algorithm.dir/main.cpp.o


CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/mainwindow.cpp

CMakeFiles/diva_algorithm.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/mainwindow.cpp > CMakeFiles/diva_algorithm.dir/mainwindow.cpp.i

CMakeFiles/diva_algorithm.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/mainwindow.cpp -o CMakeFiles/diva_algorithm.dir/mainwindow.cpp.s

CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.requires

CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.provides: CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.provides

CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.provides.build: CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o


CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o: ../AlgorithmThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/AlgorithmThread.cpp

CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/AlgorithmThread.cpp > CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.i

CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/AlgorithmThread.cpp -o CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.s

CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.requires

CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.provides: CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.provides

CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.provides.build: CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o


CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o: ../ModelRunThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/ModelRunThread.cpp

CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/ModelRunThread.cpp > CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.i

CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/ModelRunThread.cpp -o CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.s

CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.requires

CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.provides: CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.provides

CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.provides.build: CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o


CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o: sensors.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/sensors.pb.cc

CMakeFiles/diva_algorithm.dir/sensors.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/sensors.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/sensors.pb.cc > CMakeFiles/diva_algorithm.dir/sensors.pb.cc.i

CMakeFiles/diva_algorithm.dir/sensors.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/sensors.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/sensors.pb.cc -o CMakeFiles/diva_algorithm.dir/sensors.pb.cc.s

CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.requires

CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.provides: CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.provides

CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.provides.build: CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o


CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o: CMakeFiles/diva_algorithm.dir/flags.make
CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o: diva_algorithm_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o -c /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/diva_algorithm_autogen/mocs_compilation.cpp

CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/diva_algorithm_autogen/mocs_compilation.cpp > CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.i

CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/diva_algorithm_autogen/mocs_compilation.cpp -o CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.s

CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva_algorithm.dir/build.make CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o


# Object files for target diva_algorithm
diva_algorithm_OBJECTS = \
"CMakeFiles/diva_algorithm.dir/main.cpp.o" \
"CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o" \
"CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o" \
"CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o" \
"CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o" \
"CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o"

# External object files for target diva_algorithm
diva_algorithm_EXTERNAL_OBJECTS =

diva_algorithm: CMakeFiles/diva_algorithm.dir/main.cpp.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o
diva_algorithm: CMakeFiles/diva_algorithm.dir/build.make
diva_algorithm: /usr/local/lib/libzmq.so
diva_algorithm: /usr/local/lib/libopencv_gapi.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_highgui.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_ml.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_objdetect.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_photo.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_stitching.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_video.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_videoio.so.4.5.2
diva_algorithm: /usr/local/lib/libprotobuf.so
diva_algorithm: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
diva_algorithm: /usr/local/lib/libopencv_dnn.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_imgcodecs.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_calib3d.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_features2d.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_flann.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_imgproc.so.4.5.2
diva_algorithm: /usr/local/lib/libopencv_core.so.4.5.2
diva_algorithm: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
diva_algorithm: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
diva_algorithm: CMakeFiles/diva_algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable diva_algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/diva_algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/diva_algorithm.dir/build: diva_algorithm

.PHONY : CMakeFiles/diva_algorithm.dir/build

CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/main.cpp.o.requires
CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/mainwindow.cpp.o.requires
CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/AlgorithmThread.cpp.o.requires
CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/ModelRunThread.cpp.o.requires
CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/sensors.pb.cc.o.requires
CMakeFiles/diva_algorithm.dir/requires: CMakeFiles/diva_algorithm.dir/diva_algorithm_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/diva_algorithm.dir/requires

CMakeFiles/diva_algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/diva_algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/diva_algorithm.dir/clean

CMakeFiles/diva_algorithm.dir/depend: sensors.pb.cc
CMakeFiles/diva_algorithm.dir/depend: sensors.pb.h
	cd /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diva2/diva2/GroundStation/AlgorithmTesting_ka /home/diva2/diva2/GroundStation/AlgorithmTesting_ka /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build /home/diva2/diva2/GroundStation/AlgorithmTesting_ka/build/CMakeFiles/diva_algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/diva_algorithm.dir/depend

