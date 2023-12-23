cmake_minimum_required(VERSION 3.10)
project(lab7)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR
    src/npc.cpp
    src/elf.cpp
    src/knight.cpp
    src/dragon.cpp
    main.cpp
)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(lab7_lib STATIC ${SRC_DIR} ${INCLUDE_DIR})
target_include_directories(lab7_lib PUBLIC include)
target_link_libraries(lab7_lib PRIVATE Threads::Threads)

add_executable(lab7_main main.cpp)
target_link_libraries(lab7_main PRIVATE lab7_lib)

set(TEST_SRC_DIR
    test/test.cpp
)

add_executable(test ${TEST_SRC_DIR})
target_include_directories(test PRIVATE include)
target_link_libraries(test PRIVATE lab7_lib GTest::GTest GTest::Main)

add_test(NAME test COMMAND test)