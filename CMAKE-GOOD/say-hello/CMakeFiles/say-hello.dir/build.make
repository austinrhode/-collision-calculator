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
CMAKE_SOURCE_DIR = /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD

# Include any dependencies generated for this target.
include say-hello/CMakeFiles/say-hello.dir/depend.make

# Include the progress variables for this target.
include say-hello/CMakeFiles/say-hello.dir/progress.make

# Include the compile flags for this target's objects.
include say-hello/CMakeFiles/say-hello.dir/flags.make

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o: say-hello/CMakeFiles/say-hello.dir/flags.make
say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o: say-hello/src/say-hello/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o"
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o -c /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello/src/say-hello/hello.cpp

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.i"
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello/src/say-hello/hello.cpp > CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.i

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.s"
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello/src/say-hello/hello.cpp -o CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.s

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.requires:

.PHONY : say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.requires

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.provides: say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.requires
	$(MAKE) -f say-hello/CMakeFiles/say-hello.dir/build.make say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.provides.build
.PHONY : say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.provides

say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.provides.build: say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o


# Object files for target say-hello
say__hello_OBJECTS = \
"CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o"

# External object files for target say-hello
say__hello_EXTERNAL_OBJECTS =

say-hello/libsay-hello.a: say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o
say-hello/libsay-hello.a: say-hello/CMakeFiles/say-hello.dir/build.make
say-hello/libsay-hello.a: say-hello/CMakeFiles/say-hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsay-hello.a"
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && $(CMAKE_COMMAND) -P CMakeFiles/say-hello.dir/cmake_clean_target.cmake
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/say-hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
say-hello/CMakeFiles/say-hello.dir/build: say-hello/libsay-hello.a

.PHONY : say-hello/CMakeFiles/say-hello.dir/build

say-hello/CMakeFiles/say-hello.dir/requires: say-hello/CMakeFiles/say-hello.dir/src/say-hello/hello.cpp.o.requires

.PHONY : say-hello/CMakeFiles/say-hello.dir/requires

say-hello/CMakeFiles/say-hello.dir/clean:
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello && $(CMAKE_COMMAND) -P CMakeFiles/say-hello.dir/cmake_clean.cmake
.PHONY : say-hello/CMakeFiles/say-hello.dir/clean

say-hello/CMakeFiles/say-hello.dir/depend:
	cd /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello /home/garnet/Desktop/Programming/-collision-calculator/CMAKE-GOOD/say-hello/CMakeFiles/say-hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : say-hello/CMakeFiles/say-hello.dir/depend

