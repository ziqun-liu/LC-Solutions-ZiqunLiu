# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.28)

# Define the project name
project(LC0148SortList)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add an executable target for the project
add_executable(LC0148SortList
    main.cpp
    mergeSort.cpp
    insertionSort.cpp
)

# Optionally, set the output directory for the built executable
set_target_properties(LC0148SortList PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Enable debugging symbols if building in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(LC0148SortList PRIVATE -g)
endif()

# Optionally, include any additional directories for header files
# target_include_directories(LC0148SortList PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Print a message when the build configuration is generated
message(STATUS "CMake project configured for LC0148SortList")

if(MSVC)
    target_compile_options(LC0148SortList PRIVATE /Zi /Od /RTC1)
else()
    target_compile_options(LC0148SortList PRIVATE -g)
endif()
