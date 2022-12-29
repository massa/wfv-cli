cmake_minimum_required(VERSION 3.25)
include(ExternalProject)

ExternalProject_Add(
  pe_lib
  PREFIX _deps
  SOURCE_DIR _deps/src/pe_lib
  GIT_REPOSITORY https://github.com/BackupGGCode/portable-executable-library
  CONFIGURE_COMMAND ""
  BUILD_COMMAND "make pe_bliss"
  BUILD_IN_SOURCE true
  BUILD_BYPRODUCTS pe_lib/lib/libpebliss.a
  INSTALL_COMMAND ""
  )

project(wfv)
SET(CMAKE_CXX_COMPILER "clang++-14")
SET(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} wfv.cc)
target_link_libraries(${PROJECT_NAME} _deps/pe_lib/lib/libpebliss.a)

