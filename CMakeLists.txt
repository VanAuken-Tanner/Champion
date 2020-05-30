#This is a baisc example of the root CMakeLists.txt
project(Battle!)
cmake_minimum_required(VERSION 3.0)
message(STATUS "!!!!!!!!!!!!====!!!!!!!!!1${PROJECT_SOURCE_DIR}")
add_subdirectory(${PROJECT_SOURCE_DIR}/src)