cmake_minimum_required(VERSION 3.10)
project(Array C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(
    LIBRARY_SOURCES
    src/structure/array.c
)
add_library(array ${LIBRARY_SOURCES})

set(
    MANIPULATION_SOURCES
    src/manipulation/array_test.c
)

foreach(SOURCE ${MANIPULATION_SOURCES})
    get_filename_component(TEST_NAME ${SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${SOURCE})
    target_link_libraries(${TEST_NAME} array)
    target_include_directories(${TEST_NAME} PRIVATE src)
    add_test(NAME ${TEST_NAME}_test COMMAND ${TEST_NAME})
endforeach()

enable_testing()