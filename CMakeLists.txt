cmake_minimum_required(VERSION 3.25)
include(ExternalProject)

set(pe_lib_BUILD ${MAKE_COMMAND} pe_bliss)
ExternalProject_Add(
  pe_lib
  PREFIX _deps
  SOURCE_DIR _deps/src/pe_lib
  GIT_REPOSITORY https://github.com/BackupGGCode/portable-executable-library
  CONFIGURE_COMMAND ""
  CONFIGURE_HANDLED_BY_BUILD true
  BUILD_IN_SOURCE true
  INSTALL_COMMAND ""
  )

project(wfv)
SET(CMAKE_CXX_COMPILER "clang++-14")
SET(CMAKE_CXX_STANDARD 20)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
add_executable(${PROJECT_NAME} wfv.cc)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/_deps/src/pe_lib/lib/libpebliss.a -static)

