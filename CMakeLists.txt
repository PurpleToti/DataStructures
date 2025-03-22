cmake_minimum_required(VERSION 3.10)
project(GolemoStudioDataStructures C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(
    ARRAY_LIB_SOURCES
    src/array/array.c
)
add_library(array ${ARRAY_LIB_SOURCES})

set(
    DYNAMIC_ARRAY_LIB_SOURCES
    src/dynamic_array/dynamic_array.c
)
add_library(dynamic_array ${DYNAMIC_ARRAY_LIB_SOURCES})

set(
    TESTS_SOURCES
    src/tests/array_test.c
    src/tests/bordel.c
)

foreach(SOURCE ${TESTS_SOURCES})
    get_filename_component(TEST_NAME ${SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${SOURCE})

    target_link_libraries(${TEST_NAME} array)
    target_link_libraries(${TEST_NAME} dynamic_array)

    target_include_directories(${TEST_NAME} PRIVATE src)
    add_test(NAME ${TEST_NAME}_test COMMAND ${TEST_NAME})
endforeach()

enable_testing()

# Installation Instructions with golemo_structures
install(TARGETS array dynamic_array
        LIBRARY DESTINATION GolemoStudioStructures/lib
        ARCHIVE DESTINATION GolemoStudioStructures/lib)

install(DIRECTORY src/array/ DESTINATION GolemoStudioStructures/include/GolemoStudioStructures FILES_MATCHING PATTERN "*.h")
install(DIRECTORY src/dynamic_array/ DESTINATION GolemoStudioStructures/include/GolemoStudioStructures FILES_MATCHING PATTERN "*.h")