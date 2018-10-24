cmake_minimum_required(VERSION 3.9)
project(RemoteControl)

set(CMAKE_CXX_STANDARD 11)
set(REMOTECONTROL_INCLUDE_DIR include/)

include_directories(${REMOTECONTROL_INCLUDE_DIR})

add_executable(RemoteControl src/server/main.cpp src/server/Server.cpp src/RemoteControlException.cpp src/server/ServerCommand.cpp src/server/LineParser.cpp src/server/RemoteController.cpp include/RemoteController.hh)
add_executable(RemoteTarget src/client/main.cpp src/client/Client.cpp src/RemoteControlException.cpp)