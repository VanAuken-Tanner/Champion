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
CMAKE_SOURCE_DIR = /home/quiktrix/develpment_base/battle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quiktrix/develpment_base/battle/build

# Include any dependencies generated for this target.
include src/CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/game.dir/flags.make

src/CMakeFiles/game.dir/main.cpp.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quiktrix/develpment_base/battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/game.dir/main.cpp.o"
	cd /home/quiktrix/develpment_base/battle/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/main.cpp.o -c /home/quiktrix/develpment_base/battle/src/main.cpp

src/CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	cd /home/quiktrix/develpment_base/battle/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quiktrix/develpment_base/battle/src/main.cpp > CMakeFiles/game.dir/main.cpp.i

src/CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	cd /home/quiktrix/develpment_base/battle/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quiktrix/develpment_base/battle/src/main.cpp -o CMakeFiles/game.dir/main.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

src/game: src/CMakeFiles/game.dir/main.cpp.o
src/game: src/CMakeFiles/game.dir/build.make
src/game: src/libcharacter.a
src/game: src/libengine.a
src/game: src/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quiktrix/develpment_base/battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game"
	cd /home/quiktrix/develpment_base/battle/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/game.dir/build: src/game

.PHONY : src/CMakeFiles/game.dir/build

src/CMakeFiles/game.dir/clean:
	cd /home/quiktrix/develpment_base/battle/build/src && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/game.dir/clean

src/CMakeFiles/game.dir/depend:
	cd /home/quiktrix/develpment_base/battle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quiktrix/develpment_base/battle /home/quiktrix/develpment_base/battle/src /home/quiktrix/develpment_base/battle/build /home/quiktrix/develpment_base/battle/build/src /home/quiktrix/develpment_base/battle/build/src/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/game.dir/depend
