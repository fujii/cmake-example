option(libhello_is_shared "Build as a shared library" ON)

if (libhello_is_shared)
    set(lib_type SHARED)
endif()

add_library(libhello
    ${lib_type}
    hello.cxx
)

set_target_properties(
    libhello PROPERTIES
    OUTPUT_NAME hello
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
