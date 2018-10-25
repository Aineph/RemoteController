cmake_minimum_required(VERSION 2.8)
project(RemoteControl)

add_compile_options(-std=c++11)
set(REMOTECONTROL_INCLUDE_DIR include/)

include_directories(${REMOTECONTROL_INCLUDE_DIR})

add_executable(RemoteControl src/server/main.cpp src/server/Server.cpp src/RemoteControlException.cpp src/server/ServerCommand.cpp src/LineParser.cpp src/server/RemoteController.cpp include/RemoteController.hh)
add_executable(RemoteTarget src/client/main.cpp src/client/Client.cpp src/RemoteControlException.cpp src/LineParser.cpp)