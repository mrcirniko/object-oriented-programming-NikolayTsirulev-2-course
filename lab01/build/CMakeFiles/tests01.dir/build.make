# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hacker/prog/oop/lab01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hacker/prog/oop/lab01/build

# Include any dependencies generated for this target.
include CMakeFiles/tests01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests01.dir/flags.make

CMakeFiles/tests01.dir/tests01.cpp.o: CMakeFiles/tests01.dir/flags.make
CMakeFiles/tests01.dir/tests01.cpp.o: ../tests01.cpp
CMakeFiles/tests01.dir/tests01.cpp.o: CMakeFiles/tests01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hacker/prog/oop/lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests01.dir/tests01.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests01.dir/tests01.cpp.o -MF CMakeFiles/tests01.dir/tests01.cpp.o.d -o CMakeFiles/tests01.dir/tests01.cpp.o -c /home/hacker/prog/oop/lab01/tests01.cpp

CMakeFiles/tests01.dir/tests01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests01.dir/tests01.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hacker/prog/oop/lab01/tests01.cpp > CMakeFiles/tests01.dir/tests01.cpp.i

CMakeFiles/tests01.dir/tests01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests01.dir/tests01.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hacker/prog/oop/lab01/tests01.cpp -o CMakeFiles/tests01.dir/tests01.cpp.s

CMakeFiles/tests01.dir/func.cpp.o: CMakeFiles/tests01.dir/flags.make
CMakeFiles/tests01.dir/func.cpp.o: ../func.cpp
CMakeFiles/tests01.dir/func.cpp.o: CMakeFiles/tests01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hacker/prog/oop/lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests01.dir/func.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests01.dir/func.cpp.o -MF CMakeFiles/tests01.dir/func.cpp.o.d -o CMakeFiles/tests01.dir/func.cpp.o -c /home/hacker/prog/oop/lab01/func.cpp

CMakeFiles/tests01.dir/func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests01.dir/func.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hacker/prog/oop/lab01/func.cpp > CMakeFiles/tests01.dir/func.cpp.i

CMakeFiles/tests01.dir/func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests01.dir/func.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hacker/prog/oop/lab01/func.cpp -o CMakeFiles/tests01.dir/func.cpp.s

# Object files for target tests01
tests01_OBJECTS = \
"CMakeFiles/tests01.dir/tests01.cpp.o" \
"CMakeFiles/tests01.dir/func.cpp.o"

# External object files for target tests01
tests01_EXTERNAL_OBJECTS =

tests01: CMakeFiles/tests01.dir/tests01.cpp.o
tests01: CMakeFiles/tests01.dir/func.cpp.o
tests01: CMakeFiles/tests01.dir/build.make
tests01: /usr/local/lib/libgtest.a
tests01: CMakeFiles/tests01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hacker/prog/oop/lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests01.dir/build: tests01
.PHONY : CMakeFiles/tests01.dir/build

CMakeFiles/tests01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests01.dir/clean

CMakeFiles/tests01.dir/depend:
	cd /home/hacker/prog/oop/lab01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hacker/prog/oop/lab01 /home/hacker/prog/oop/lab01 /home/hacker/prog/oop/lab01/build /home/hacker/prog/oop/lab01/build /home/hacker/prog/oop/lab01/build/CMakeFiles/tests01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests01.dir/depend

