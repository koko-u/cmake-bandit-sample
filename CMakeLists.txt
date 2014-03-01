cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME_STR sample_fraction)
project(${PROJECT_NAME_STR} C CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-Wall --std=c++11 -pthread)
endif()

#----------------------------------------
# set common include folder for module
#----------------------------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

#----------------------------------------
# Module source
#----------------------------------------
set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_impl)

include_directories(${COMMON_INCLUDES})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_LIB_NAME} ${SRC_FILES})

#----------------------------------------
# Test
#----------------------------------------
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
set(BANDIT_ROOT_DIR ${EXT_PROJECTS_DIR}/bandit)
include_directories(${BANDIT_ROOT_DIR} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIB_NAME})

if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(${PROJECT_TEST_NAME} pthread)
endif()

add_test(test1 ${PROJECT_TEST_NAME})
