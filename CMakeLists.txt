#This is a baisc example of the root CMakeLists.txt
project(Battle!)
cmake_minimum_required(VERSION 3.0)
message(STATUS "gettingSDL")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

message(STATUS "!!!!!!!!!!!!====!!!!!!!!!${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)