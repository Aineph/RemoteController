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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nicolas/Documents/Pangolin/RemoteControl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx

# Include any dependencies generated for this target.
include CMakeFiles/RemoteTarget.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RemoteTarget.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RemoteTarget.dir/flags.make

CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o: CMakeFiles/RemoteTarget.dir/flags.make
CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o: ../../src/client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/main.cpp

CMakeFiles/RemoteTarget.dir/src/client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteTarget.dir/src/client/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/main.cpp > CMakeFiles/RemoteTarget.dir/src/client/main.cpp.i

CMakeFiles/RemoteTarget.dir/src/client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteTarget.dir/src/client/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/main.cpp -o CMakeFiles/RemoteTarget.dir/src/client/main.cpp.s

CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o: CMakeFiles/RemoteTarget.dir/flags.make
CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o: ../../src/client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/Client.cpp

CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/Client.cpp > CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.i

CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/Client.cpp -o CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.s

CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o: CMakeFiles/RemoteTarget.dir/flags.make
CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o: ../../src/RemoteControlException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp

CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp > CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.i

CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/RemoteControlException.cpp -o CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.s

CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o: CMakeFiles/RemoteTarget.dir/flags.make
CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o: ../../src/LineParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/LineParser.cpp

CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/LineParser.cpp > CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.i

CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/LineParser.cpp -o CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.s

CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o: CMakeFiles/RemoteTarget.dir/flags.make
CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o: ../../src/client/CommandInterpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o -c /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/CommandInterpreter.cpp

CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/CommandInterpreter.cpp > CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.i

CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolas/Documents/Pangolin/RemoteControl/src/client/CommandInterpreter.cpp -o CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.s

# Object files for target RemoteTarget
RemoteTarget_OBJECTS = \
"CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o" \
"CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o" \
"CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o" \
"CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o" \
"CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o"

# External object files for target RemoteTarget
RemoteTarget_EXTERNAL_OBJECTS =

RemoteTarget: CMakeFiles/RemoteTarget.dir/src/client/main.cpp.o
RemoteTarget: CMakeFiles/RemoteTarget.dir/src/client/Client.cpp.o
RemoteTarget: CMakeFiles/RemoteTarget.dir/src/RemoteControlException.cpp.o
RemoteTarget: CMakeFiles/RemoteTarget.dir/src/LineParser.cpp.o
RemoteTarget: CMakeFiles/RemoteTarget.dir/src/client/CommandInterpreter.cpp.o
RemoteTarget: CMakeFiles/RemoteTarget.dir/build.make
RemoteTarget: CMakeFiles/RemoteTarget.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable RemoteTarget"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemoteTarget.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RemoteTarget.dir/build: RemoteTarget

.PHONY : CMakeFiles/RemoteTarget.dir/build

CMakeFiles/RemoteTarget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RemoteTarget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RemoteTarget.dir/clean

CMakeFiles/RemoteTarget.dir/depend:
	cd /Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nicolas/Documents/Pangolin/RemoteControl /Users/nicolas/Documents/Pangolin/RemoteControl /Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx /Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx /Users/nicolas/Documents/Pangolin/RemoteControl/bin/mac-osx/CMakeFiles/RemoteTarget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RemoteTarget.dir/depend

