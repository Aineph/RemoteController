# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nicolas/Documents/Pangolin/RemoteControl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nicolas/Documents/Pangolin/RemoteControl/build

# Include any dependencies generated for this target.
include CMakeFiles/RemoteControl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RemoteControl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RemoteControl.dir/flags.make

CMakeFiles/RemoteControl.dir/src/server/main.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/server/main.cpp.o: ../src/server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RemoteControl.dir/src/server/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/server/main.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/main.cpp

CMakeFiles/RemoteControl.dir/src/server/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/server/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/main.cpp > CMakeFiles/RemoteControl.dir/src/server/main.cpp.i

CMakeFiles/RemoteControl.dir/src/server/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/server/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/main.cpp -o CMakeFiles/RemoteControl.dir/src/server/main.cpp.s

CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o: ../src/server/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/Server.cpp

CMakeFiles/RemoteControl.dir/src/server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/server/Server.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/Server.cpp > CMakeFiles/RemoteControl.dir/src/server/Server.cpp.i

CMakeFiles/RemoteControl.dir/src/server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/server/Server.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/Server.cpp -o CMakeFiles/RemoteControl.dir/src/server/Server.cpp.s

CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o: ../src/RemoteControlException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp

CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp > CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.i

CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp -o CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.s

CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o: ../src/server/ServerCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/ServerCommand.cpp

CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/ServerCommand.cpp > CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.i

CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/ServerCommand.cpp -o CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.s

CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o: ../src/server/LineParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/LineParser.cpp

CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/LineParser.cpp > CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.i

CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/LineParser.cpp -o CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.s

CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o: CMakeFiles/RemoteControl.dir/flags.make
CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o: ../src/server/RemoteController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/RemoteController.cpp

CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/RemoteController.cpp > CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.i

CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/server/RemoteController.cpp -o CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.s

# Object files for target RemoteControl
RemoteControl_OBJECTS = \
"CMakeFiles/RemoteControl.dir/src/server/main.cpp.o" \
"CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o" \
"CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o" \
"CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o" \
"CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o" \
"CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o"

# External object files for target RemoteControl
RemoteControl_EXTERNAL_OBJECTS =

RemoteControl: CMakeFiles/RemoteControl.dir/src/server/main.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/src/server/Server.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/src/RemoteControlException.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/src/server/ServerCommand.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/src/server/LineParser.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/src/server/RemoteController.cpp.o
RemoteControl: CMakeFiles/RemoteControl.dir/build.make
RemoteControl: CMakeFiles/RemoteControl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RemoteControl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemoteControl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RemoteControl.dir/build: RemoteControl

.PHONY : CMakeFiles/RemoteControl.dir/build

CMakeFiles/RemoteControl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RemoteControl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RemoteControl.dir/clean

CMakeFiles/RemoteControl.dir/depend:
	cd /Users/nicolas/Documents/Pangolin/RemoteControl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nicolas/Documents/Pangolin/RemoteControl /Users/nicolas/Documents/Pangolin/RemoteControl /Users/nicolas/Documents/Pangolin/RemoteControl/build /Users/nicolas/Documents/Pangolin/RemoteControl/build /Users/nicolas/Documents/Pangolin/RemoteControl/build/CMakeFiles/RemoteControl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RemoteControl.dir/depend

