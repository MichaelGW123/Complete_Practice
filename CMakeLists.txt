cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find required packages
find_package(Qt5 5.15.3 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Threads REQUIRED)
set(CMAKE_AUTOMOC)
set(CMAKE_AUTORCC)
set(CMAKE_AUTOUIC)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR/Framework/Defs})

# Add subdirectories
add_subdirectory(Framework)
add_subdirectory(Input)
add_subdirectory(Flip_H)
add_subdirectory(Flip_V)
add_subdirectory(Rotate_CW)
add_subdirectory(Rotate_CCW)
