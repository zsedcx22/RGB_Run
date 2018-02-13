cmake_minimum_required(VERSION 3.9)
#this sets a required minimum version of C++ 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(rgbRun)

###Setup directories

#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

#output all DLLs from all libs to main build folder
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

##Add External dependencies
add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

### rgbrun
file(GLOB_RECURSE SOURCES rgbrun/*.cpp rgbrun/*.h)
add_executable(rgbrun ${SOURCES})
target_include_directories(rgbrun PRIVATE ${SFML_INCS})
target_link_libraries(rgbrun sfml-graphics)

