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
CMAKE_SOURCE_DIR = /home/breadlofe/Desktop/Data_Structures/ssuds_pp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build

# Include any dependencies generated for this target.
include CMakeFiles/ssuds_pp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ssuds_pp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ssuds_pp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ssuds_pp.dir/flags.make

CMakeFiles/ssuds_pp.dir/main.cpp.o: CMakeFiles/ssuds_pp.dir/flags.make
CMakeFiles/ssuds_pp.dir/main.cpp.o: ../main.cpp
CMakeFiles/ssuds_pp.dir/main.cpp.o: CMakeFiles/ssuds_pp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ssuds_pp.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ssuds_pp.dir/main.cpp.o -MF CMakeFiles/ssuds_pp.dir/main.cpp.o.d -o CMakeFiles/ssuds_pp.dir/main.cpp.o -c /home/breadlofe/Desktop/Data_Structures/ssuds_pp/main.cpp

CMakeFiles/ssuds_pp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ssuds_pp.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breadlofe/Desktop/Data_Structures/ssuds_pp/main.cpp > CMakeFiles/ssuds_pp.dir/main.cpp.i

CMakeFiles/ssuds_pp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ssuds_pp.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breadlofe/Desktop/Data_Structures/ssuds_pp/main.cpp -o CMakeFiles/ssuds_pp.dir/main.cpp.s

# Object files for target ssuds_pp
ssuds_pp_OBJECTS = \
"CMakeFiles/ssuds_pp.dir/main.cpp.o"

# External object files for target ssuds_pp
ssuds_pp_EXTERNAL_OBJECTS =

ssuds_pp: CMakeFiles/ssuds_pp.dir/main.cpp.o
ssuds_pp: CMakeFiles/ssuds_pp.dir/build.make
ssuds_pp: CMakeFiles/ssuds_pp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ssuds_pp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ssuds_pp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ssuds_pp.dir/build: ssuds_pp
.PHONY : CMakeFiles/ssuds_pp.dir/build

CMakeFiles/ssuds_pp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ssuds_pp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ssuds_pp.dir/clean

CMakeFiles/ssuds_pp.dir/depend:
	cd /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/breadlofe/Desktop/Data_Structures/ssuds_pp /home/breadlofe/Desktop/Data_Structures/ssuds_pp /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles/ssuds_pp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ssuds_pp.dir/depend

