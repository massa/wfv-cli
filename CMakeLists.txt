cmake_minimum_required(VERSION 3.25)
include(ExternalProject)

set(pe_lib_BUILD ${MAKE_COMMAND} pe_bliss)
ExternalProject_Add(
  pe_lib
  PREFIX _deps
  SOURCE_DIR _deps/src/pe_lib
  GIT_REPOSITORY https://github.com/massa/portable-executable-library
  CONFIGURE_COMMAND ""
  CONFIGURE_HANDLED_BY_BUILD true
  BUILD_IN_SOURCE true
  INSTALL_COMMAND ""
  )

project(wfv)
SET(CMAKE_CXX_STANDARD 26)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
add_executable(${PROJECT_NAME} wfv.cc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/_deps/src/pe_lib/pe_lib/)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/_deps/src/pe_lib/lib/libpebliss.a -static)
