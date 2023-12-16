cmake_minimum_required(VERSION 3.20)
project(lab05)

find_package(GTest REQUIRED)

##set(CMAKE_CXX_STANDARD 20)
##set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

add_library(lab5_lib INTERFACE)
target_include_directories(lab5_lib INTERFACE ${INCLUDE_DIR})
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.cpp)

add_executable(lab05_test ${TEST_SOURCES})
target_link_libraries(lab05_test PRIVATE lab5_lib GTest::GTest GTest::Main)

find_package(Threads REQUIRED) 
target_link_libraries(lab05_test PRIVATE Threads::Threads) 


add_test(NAME lab05_test COMMAND lab05_test)