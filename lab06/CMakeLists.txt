cmake_minimum_required(VERSION 3.10)
project(lab6)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR
    src/npc.cpp
    src/observer.cpp
    src/visitor.cpp
    src/factory.cpp
    src/elf.cpp
    src/knight.cpp
    src/dragon.cpp
    main.cpp
)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(lab6_lib STATIC ${SRC_DIR} ${INCLUDE_DIR})
target_include_directories(lab6_lib PUBLIC include)

add_executable(lab6_main main.cpp)
target_link_libraries(lab6_main PRIVATE lab6_lib)

set(TEST_SRC_DIR
    test/test.cpp
)

add_executable(test ${TEST_SRC_DIR})
target_include_directories(test PRIVATE include)
target_link_libraries(test PRIVATE lab6_lib GTest::GTest GTest::Main)

add_test(NAME test COMMAND test)