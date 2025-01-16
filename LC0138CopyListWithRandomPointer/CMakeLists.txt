# CMakeList.txt : CMake project for LC138CopyListWithRandomPointer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LC0138CopyListWithRandomPointer")

# Add source to this project's executable.
add_executable (LC0138CopyListWithRandomPointer "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LC0138CopyListWithRandomPointer PROPERTY CXX_STANDARD 20)
endif()

