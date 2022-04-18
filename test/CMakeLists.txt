cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/googletest/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp contoTest.cpp)
add_executable(runTFtests ${TEST_SOURCE_FILES})
target_link_libraries(runTFtests gtest gtest_main core)