
add_executable(hello
  hello.cxx
)

install(TARGETS hello
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
