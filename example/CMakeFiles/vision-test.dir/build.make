# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/ubuntu/DriverlessCarChallenge_2017-2018/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/DriverlessCarChallenge_2017-2018/example

# Include any dependencies generated for this target.
include CMakeFiles/vision-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vision-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vision-test.dir/flags.make

# Object files for target vision-test
vision__test_OBJECTS =

# External object files for target vision-test
vision__test_EXTERNAL_OBJECTS =

bin/Release/vision-test: CMakeFiles/vision-test.dir/build.make
bin/Release/vision-test: bin/Release/libopenni2.a
bin/Release/vision-test: bin/Release/libi2c-pwm.a
bin/Release/vision-test: bin/Release/libmultilane.a
bin/Release/vision-test: bin/Release/libHAL.a
bin/Release/vision-test: bin/Release/libSignDetection.a
bin/Release/vision-test: bin/Release/libsignsRecognizer.a
bin/Release/vision-test: bin/Release/libradon.a
bin/Release/vision-test: bin/Release/libextractInfo.a
bin/Release/vision-test: bin/Release/libradon.a
bin/Release/vision-test: bin/Release/libvanishing-point.a
bin/Release/vision-test: /usr/local/lib/libopencv_videostab.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_ccalib.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_fuzzy.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_rgbd.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_xfeatures2d.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_shape.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_video.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_ximgproc.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_calib3d.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_features2d.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_flann.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_xobjdetect.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_objdetect.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_ml.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_xphoto.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_highgui.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_photo.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_videoio.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_imgproc.so.3.2.0
bin/Release/vision-test: /usr/local/lib/libopencv_core.so.3.2.0
bin/Release/vision-test: CMakeFiles/vision-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/Release/vision-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vision-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vision-test.dir/build: bin/Release/vision-test
.PHONY : CMakeFiles/vision-test.dir/build

CMakeFiles/vision-test.dir/requires:
.PHONY : CMakeFiles/vision-test.dir/requires

CMakeFiles/vision-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vision-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vision-test.dir/clean

CMakeFiles/vision-test.dir/depend:
	cd /home/ubuntu/DriverlessCarChallenge_2017-2018/example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/DriverlessCarChallenge_2017-2018/example /home/ubuntu/DriverlessCarChallenge_2017-2018/example /home/ubuntu/DriverlessCarChallenge_2017-2018/example /home/ubuntu/DriverlessCarChallenge_2017-2018/example /home/ubuntu/DriverlessCarChallenge_2017-2018/example/CMakeFiles/vision-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vision-test.dir/depend

