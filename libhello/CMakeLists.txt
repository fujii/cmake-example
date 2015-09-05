add_library(libhello
    hello.cxx
)

set_target_properties(
    libhello PROPERTIES
    OUTPUT_NAME hello
)

target_include_directories(
    libhello
    PRIVATE include
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set(api_header_files
    include/hello/export.h
    include/hello/hello.h
)
target_sources(libhello PRIVATE ${api_header_files})

target_compile_definitions(
    libhello PRIVATE LIBHELLO_EXPORTS
)

install(TARGETS libhello
    EXPORT libhello
    RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT libhello
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

install(
    FILES ${api_header_files}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hello
    COMPONENT headers
)
