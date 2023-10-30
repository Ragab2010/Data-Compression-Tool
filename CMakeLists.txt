cmake_minimum_required(VERSION 3.12)

project(MyHuffmanProject)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(include)

# Locate necessary packages and libraries here if needed

# Add the source files to the project
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(MyHuffmanProject ${SOURCES})

# Set the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

