add_library(hello
    hello.cxx)

generate_export_header(hello)

target_include_directories(
    hello
    PRIVATE
        include
        ${CMAKE_CURRENT_BINARY_DIR}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set(api_header_files
    include/hello/hello.h)

target_sources(hello PRIVATE ${api_header_files})

install(TARGETS hello
    EXPORT hello-config
    RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT hello-config
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)

install(
    FILES
        ${api_header_files}
        ${CMAKE_CURRENT_BINARY_DIR}/hello_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hello
    COMPONENT headers)
