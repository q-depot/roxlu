# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-3.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/src/main.mm.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/main.mm.o: ../src/main.mm
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/src/main.mm.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/main.mm.o -c /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/main.mm

CMakeFiles/test.dir/src/main.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/main.mm.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/main.mm > CMakeFiles/test.dir/src/main.mm.i

CMakeFiles/test.dir/src/main.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/main.mm.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/main.mm -o CMakeFiles/test.dir/src/main.mm.s

CMakeFiles/test.dir/src/main.mm.o.requires:
.PHONY : CMakeFiles/test.dir/src/main.mm.o.requires

CMakeFiles/test.dir/src/main.mm.o.provides: CMakeFiles/test.dir/src/main.mm.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/main.mm.o.provides.build
.PHONY : CMakeFiles/test.dir/src/main.mm.o.provides

CMakeFiles/test.dir/src/main.mm.o.provides.build: CMakeFiles/test.dir/src/main.mm.o
.PHONY : CMakeFiles/test.dir/src/main.mm.o.provides.build

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/src/main.mm.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/src/main.mm.o
test: RoxluMultiTouch.a
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/src/main.mm.o.requires
.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
