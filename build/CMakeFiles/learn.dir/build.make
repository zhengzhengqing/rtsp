# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/zzq/work/audio_player

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzq/work/audio_player/build

# Include any dependencies generated for this target.
include CMakeFiles/learn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn.dir/flags.make

CMakeFiles/learn.dir/learn.cpp.o: CMakeFiles/learn.dir/flags.make
CMakeFiles/learn.dir/learn.cpp.o: ../learn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzq/work/audio_player/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learn.dir/learn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn.dir/learn.cpp.o -c /home/zzq/work/audio_player/learn.cpp

CMakeFiles/learn.dir/learn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn.dir/learn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzq/work/audio_player/learn.cpp > CMakeFiles/learn.dir/learn.cpp.i

CMakeFiles/learn.dir/learn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn.dir/learn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzq/work/audio_player/learn.cpp -o CMakeFiles/learn.dir/learn.cpp.s

# Object files for target learn
learn_OBJECTS = \
"CMakeFiles/learn.dir/learn.cpp.o"

# External object files for target learn
learn_EXTERNAL_OBJECTS =

learn: CMakeFiles/learn.dir/learn.cpp.o
learn: CMakeFiles/learn.dir/build.make
learn: CMakeFiles/learn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzq/work/audio_player/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn.dir/build: learn

.PHONY : CMakeFiles/learn.dir/build

CMakeFiles/learn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn.dir/clean

CMakeFiles/learn.dir/depend:
	cd /home/zzq/work/audio_player/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzq/work/audio_player /home/zzq/work/audio_player /home/zzq/work/audio_player/build /home/zzq/work/audio_player/build /home/zzq/work/audio_player/build/CMakeFiles/learn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn.dir/depend

