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
CMAKE_SOURCE_DIR = /home/hacker/prog/oop/lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hacker/prog/oop/lab6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab06_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab06_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab06_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab06_exe.dir/flags.make

CMakeFiles/lab06_exe.dir/main.cpp.o: CMakeFiles/lab06_exe.dir/flags.make
CMakeFiles/lab06_exe.dir/main.cpp.o: ../main.cpp
CMakeFiles/lab06_exe.dir/main.cpp.o: CMakeFiles/lab06_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hacker/prog/oop/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab06_exe.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab06_exe.dir/main.cpp.o -MF CMakeFiles/lab06_exe.dir/main.cpp.o.d -o CMakeFiles/lab06_exe.dir/main.cpp.o -c /home/hacker/prog/oop/lab6/main.cpp

CMakeFiles/lab06_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab06_exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hacker/prog/oop/lab6/main.cpp > CMakeFiles/lab06_exe.dir/main.cpp.i

CMakeFiles/lab06_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab06_exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hacker/prog/oop/lab6/main.cpp -o CMakeFiles/lab06_exe.dir/main.cpp.s

# Object files for target lab06_exe
lab06_exe_OBJECTS = \
"CMakeFiles/lab06_exe.dir/main.cpp.o"

# External object files for target lab06_exe
lab06_exe_EXTERNAL_OBJECTS =

lab06_exe: CMakeFiles/lab06_exe.dir/main.cpp.o
lab06_exe: CMakeFiles/lab06_exe.dir/build.make
lab06_exe: CMakeFiles/lab06_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hacker/prog/oop/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab06_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab06_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab06_exe.dir/build: lab06_exe
.PHONY : CMakeFiles/lab06_exe.dir/build

CMakeFiles/lab06_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab06_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab06_exe.dir/clean

CMakeFiles/lab06_exe.dir/depend:
	cd /home/hacker/prog/oop/lab6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hacker/prog/oop/lab6 /home/hacker/prog/oop/lab6 /home/hacker/prog/oop/lab6/build /home/hacker/prog/oop/lab6/build /home/hacker/prog/oop/lab6/build/CMakeFiles/lab06_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab06_exe.dir/depend

