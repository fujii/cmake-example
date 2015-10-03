add_library(libhello
  hello.cxx
)

set_target_properties(
  libhello PROPERTIES
  OUTPUT_NAME hello
)

generate_export_header(libhello)

target_include_directories(
  libhello
  PRIVATE
    include
    ${CMAKE_CURRENT_BINARY_DIR}
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set(api_header_files
  include/hello/hello.h
)
target_sources(libhello PRIVATE ${api_header_files})

install(TARGETS libhello
  EXPORT libhello-config
  RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT libhello-config
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

install(
  FILES
    ${api_header_files}
    ${CMAKE_CURRENT_BINARY_DIR}/libhello_export.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hello
  COMPONENT headers
)
