# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/double_items.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/double_items.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/double_items.dir/flags.make

CMakeFiles/double_items.dir/main.cpp.o: CMakeFiles/double_items.dir/flags.make
CMakeFiles/double_items.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/double_items.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/double_items.dir/main.cpp.o -c /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/main.cpp

CMakeFiles/double_items.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/double_items.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/main.cpp > CMakeFiles/double_items.dir/main.cpp.i

CMakeFiles/double_items.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/double_items.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/main.cpp -o CMakeFiles/double_items.dir/main.cpp.s

# Object files for target double_items
double_items_OBJECTS = \
"CMakeFiles/double_items.dir/main.cpp.o"

# External object files for target double_items
double_items_EXTERNAL_OBJECTS =

double_items: CMakeFiles/double_items.dir/main.cpp.o
double_items: CMakeFiles/double_items.dir/build.make
double_items: CMakeFiles/double_items.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable double_items"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/double_items.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/double_items.dir/build: double_items

.PHONY : CMakeFiles/double_items.dir/build

CMakeFiles/double_items.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/double_items.dir/cmake_clean.cmake
.PHONY : CMakeFiles/double_items.dir/clean

CMakeFiles/double_items.dir/depend:
	cd /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug /Users/takacsanna/Desktop/ferrilata/radars/annatakacs/week-01/day-04/double_items/cmake-build-debug/CMakeFiles/double_items.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/double_items.dir/depend

