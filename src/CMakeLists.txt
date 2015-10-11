
add_executable(hello
  hello.cxx)

target_link_libraries(hello libhello)

install(TARGETS hello
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_test(NAME hello-run COMMAND hello)
add_test(NAME hello-version COMMAND hello --version)
