cmake_minimum_required(VERSION 3.9)
# Compiler flags
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHsc" CACHE INTERNAL "" FORCE)
elseif(APPLE)
  message("hello apple")
  set(CMAKE_OSX_DEPLOYMENT_TARGET 10.9 CACHE STRING "")
endif()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
# SFML - graphics library
add_subdirectory("lib/sfml")
#include_directories("lib/sfml/include")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

#### Add Engine and our own library projects####

file(GLOB_RECURSE RESOURCE_FILES "resources/*.*")
####
file(GLOB_RECURSE SOURCE_FILES engine/src/*.cpp engine/src/*.h)
add_library(lib_engine STATIC ${SOURCE_FILES} ${RESOURCE_FILES})
target_include_directories(lib_engine INTERFACE "${CMAKE_SOURCE_DIR}/engine/src/" )
target_link_libraries(lib_engine lib_maths lib_ecm sfml-graphics sfml-audio)
## Maths lib
file(GLOB_RECURSE SOURCE_FILES engine/lib_maths/*.cpp engine/lib_maths/*.h)
add_library(lib_maths INTERFACE)
target_sources(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/engine/lib_maths/maths.h")
target_include_directories(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/engine/lib_maths" SYSTEM INTERFACE ${SFML_INCS})

## ECM lib
file(GLOB_RECURSE SOURCE_FILES engine/lib_ecm/*.cpp engine/lib_ecm/*.h)
add_library(lib_ecm STATIC ${SOURCE_FILES})
target_include_directories(lib_ecm INTERFACE "${CMAKE_SOURCE_DIR}/engine/lib_ecm" )
target_link_libraries(lib_ecm PRIVATE lib_maths)

#### Add Practical Projects####
## platformer
file(GLOB_RECURSE SOURCES platformer/*.cpp platformer/*.h)
file(GLOB_RECURSE CMPNTS platformer/components/*.cpp platformer/components/*.h)
file(GLOB_RECURSE SCENES platformer/scenes/*.cpp platformer/scenes/*.h)
add_executable(platformer ${SOURCES} ${RESOURCE_FILES})
source_group("components" FILES ${CMPNTS})
source_group("resources" FILES ${RESOURCE_FILES})
#target_include_directories(platformer SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(platformer lib_engine)
set(EXECUTABLES ${EXECUTABLES} platformer)


#### Target for copying resources to build dir####
if(APPLE)
  add_custom_target(copy_resources ALL
          COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${PROJECT_SOURCE_DIR}/resources" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
          COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${CMAKE_SOURCE_DIR}/lib/sfml/extlibs/libs-osx/Frameworks" ${CMAKE_BINARY_DIR}/lib/sfml/Frameworks
          )
else()
  add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${PROJECT_SOURCE_DIR}/resources" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/resources
          )
endif()

#### Link Dependencies ####
foreach (exe ${EXECUTABLES})
  #Set working directory to build dir
  set_target_properties(${exe} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
  )

  target_link_libraries(${exe}
          lib_maths
    optimized sfml-graphics debug sfml-graphics-d
    optimized sfml-audio debug sfml-audio-d
    optimized sfml-window debug sfml-window-d
    optimized sfml-system debug sfml-system-d
    optimized sfml-graphics debug sfml-graphics-d
    #optimized sfml-main
  )

  #target_link_libraries(${exe} "${CMAKE_SOURCE_DIR}/lib/sfml/extlibs/libs-osx/Frameworks/f??reetype.framework/Ve??rsions/A/freetype")
  add_dependencies(${exe} sfml-graphics sfml-audio copy_resources)
endforeach ()
