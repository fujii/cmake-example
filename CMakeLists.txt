cmake_minimum_required(VERSION 3.3)

project(hello VERSION 0.1 LANGUAGES CXX)

include(GNUInstallDirs)
include(GenerateExportHeader)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

option(BUILD_SHARED_LIBS "Create shared libraries" ON)

add_subdirectory(libhello)
add_subdirectory(src)
