cmake_minimum_required(VERSION 3.21)
project(UnuqMPAutomat)

set(CMAKE_CXX_STANDARD 23)

add_executable(UnuqMPAutomat main.cpp state.cpp state.h stateList.cpp stateList.h utils.cpp utils.h automatM.cpp automatM.h)
