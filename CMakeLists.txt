cmake_minimum_required(VERSION 3.3)

project(hello VERSION 0.1 LANGUAGES CXX)

enable_testing()
include(GNUInstallDirs)
include(GenerateExportHeader)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

# for Windows, dll should be in the same directory with exe files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)

option(BUILD_SHARED_LIBS "Create shared libraries" ON)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
include(CPack)

add_subdirectory(libhello)
add_subdirectory(src)
