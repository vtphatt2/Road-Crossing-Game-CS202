# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/src/main.cpp
CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/main.cpp.o -MF CMakeFiles/game.dir/src/main.cpp.o.d -o CMakeFiles/game.dir/src/main.cpp.o -c /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/main.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/build.make
game: /opt/homebrew/lib/libsfml-graphics.2.6.0.dylib
game: /opt/homebrew/lib/libsfml-window.2.6.0.dylib
game: /opt/homebrew/lib/libsfml-system.2.6.0.dylib
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202 /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202 /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build /Users/VoThinhPhat/Desktop/Road-Crossing-Game-CS202/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend
