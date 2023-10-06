cmake_minimum_required(VERSION 3.13.0)
project(QtSimple LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "-fopenmp")

# Packages
find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Enable Qt MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Source Files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/gui/*.cpp)
message(${SRC_FILES})
set(LIBS Qt5::Widgets ${OPENGL_LIBRARIES} pthread)

# Includes
include_directories(${OPENGL_INCLUDE_DIR} gui)

# Application
add_executable(QtSimple_run main/main.cpp ${SRC_FILES})
target_link_libraries(QtSimple_run ${LIBS})