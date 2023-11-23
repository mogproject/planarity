cmake_minimum_required(VERSION 3.14)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# check boost root
if (NOT DEFINED BOOST_ROOT OR "${BOOST_ROOT}" STREQUAL "")
  message(FATAL_ERROR "Environment variable `BOOST_ROOT` is not properly set. Exiting." )
endif ()

# main source
file(GLOB_RECURSE MAIN_SRC
  src/readwrite/*.[ch]pp
  src/util/*.[ch]pp
)

# libraries
include_directories(
  src
  lib/CLI11
  ${BOOST_ROOT}
)

# project
project(planarity)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -Wall -funroll-loops -fno-stack-limit -O3")
add_executable(planarity src/planarity.cpp ${MAIN_SRC})
