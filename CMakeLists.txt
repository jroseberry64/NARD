cmake_minimum_required(VERSION 2.8.9)

project(NARD)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_STANDARD "11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_EXE_LINKER_FLAGS "-lncurses")

file(GLOB SOURCES "src/*.cpp")

add_executable(NARD ${SOURCES})

#Junk:
#cmake -D CMAKE_CXX_COMPILER=g++ "{which g++}" .
#run above line to change compiler to g++
#set(CMAKE_CXX_FLAGS "clang++") #${CMAKE_CXX_FLAGS}