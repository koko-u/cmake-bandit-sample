cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME_STR sample_fraction)
project(${PROJECT_NAME_STR} C CXX)

#----------------------------------------
# set compiler
#----------------------------------------
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-Wall -std=c++11 -pthread)
endif()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  add_definitions(-pedantic -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -std=c++11)
  include_directories(/usr/local/include/c++/v1)
  link_directories(/usr/local/lib)
  link_libraries(c++)
endif()

#----------------------------------------
# set common include folder for module
#----------------------------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

#----------------------------------------
# Module source
#----------------------------------------
set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}Lib)

include_directories(${COMMON_INCLUDES})
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_LIB_NAME} ${SRC_FILES})

#----------------------------------------
# Test
#----------------------------------------
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}Test)
set(BANDIT_ROOT_DIR ${EXT_PROJECTS_DIR}/bandit)
include_directories(${BANDIT_ROOT_DIR} ${COMMON_INCLUDES})

file(GLOB_RECURSE TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIB_NAME})

if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(${PROJECT_TEST_NAME} pthread)
endif()

add_test(test1 ${PROJECT_TEST_NAME})

#----------------------------------------
# Application
#----------------------------------------
set(APPLICATION_NAME ${PROJECT_NAME_STR})
add_executable(${APPLICATION_NAME} main.cpp)
target_link_libraries(${APPLICATION_NAME} ${PROJECT_LIB_NAME})
install(TARGETS ${APPLICATION_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)

#----------------------------------------
# Doxygen
#----------------------------------------
option(BUILD_DOC "Use Doxygen to create the HTML based API documentation" OFF)
if(BUILD_DOC)
  FIND_PACKAGE(Doxygen)
  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build documentation. Please install it")
  endif()
  configure_file(Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile @ONLY IMMEDIATE)
  add_custom_target(doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
    SOURCES ${PROJECT_BINARY_DIR}/Doxyfile)
endif()