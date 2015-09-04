cmake_minimum_required(VERSION 3.3)

project(hello VERSION 0.1 LANGUAGES CXX)

include(GNUInstallDirs)

add_subdirectory(libhello)
add_subdirectory(src)
