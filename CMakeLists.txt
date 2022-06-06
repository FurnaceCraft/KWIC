cmake_minimum_required(VERSION 3.21)
project(mykwic)

set(CMAKE_CXX_STANDARD 14)

add_executable(mykwic main.cpp LineStorage.cpp LineStorage.h Input.cpp Input.h Shifter.cpp Shifter.h Sorter.cpp Sorter.h Output.cpp Output.h Searcher.cpp Searcher.h Graphics.cpp Graphics.h)
