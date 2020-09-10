
add_executable(hello_test
    hello.cxx)

target_link_libraries(hello_test hello)

install(TARGETS hello
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_test(NAME hello-run COMMAND hello_test)
add_test(NAME hello-version COMMAND hello_test --version)
