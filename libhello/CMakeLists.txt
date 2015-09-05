add_library(libhello
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
