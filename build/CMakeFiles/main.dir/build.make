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
CMAKE_SOURCE_DIR = /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/sampletest.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/sampletest.cpp.o: /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/sampletest.cpp
CMakeFiles/main.dir/sampletest.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/sampletest.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/sampletest.cpp.o -MF CMakeFiles/main.dir/sampletest.cpp.o.d -o CMakeFiles/main.dir/sampletest.cpp.o -c /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/sampletest.cpp

CMakeFiles/main.dir/sampletest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/sampletest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/sampletest.cpp > CMakeFiles/main.dir/sampletest.cpp.i

CMakeFiles/main.dir/sampletest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/sampletest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src/sampletest.cpp -o CMakeFiles/main.dir/sampletest.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/sampletest.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main: CMakeFiles/main.dir/main.cpp.o
/home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main: CMakeFiles/main.dir/sampletest.cpp.o
/home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main: CMakeFiles/main.dir/build.make
/home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: /home/breadlofe/Desktop/Data_Structures/ssuds_pp/bin/main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src /home/breadlofe/Desktop/Data_Structures/ssuds_pp/src /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build /home/breadlofe/Desktop/Data_Structures/ssuds_pp/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

