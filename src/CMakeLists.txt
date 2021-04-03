cmake_minimum_required(VERSION 3.10)

# Jmeno projektu
project(Kalkulacka)

# -std=c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)     # .so
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)     # .a

# Include hlavickovych souboru ve slozce include
include_directories(include)

# Nastaveni promennych
set(TEST_SOURCE test_lib)
set(MATH_LIB math_lib)
set(PROFILING profiling)

add_subdirectory(googletest)
add_subdirectory(gui)

# Tvorba spustitelneho "./test_lib"
# g++ -o ${TEST_SOURCE} ${TEST_SOURCE} -L. -l${MATH_LIB} -lgtest -lgtest_main
add_executable(${TEST_SOURCE} ${TEST_SOURCE}.cpp)
target_link_libraries(${TEST_SOURCE} PRIVATE ${MATH_LIB} gtest gtest_main)

# Tvorba spustitelneho ./profiling
add_executable(${PROFILING} profiling.cpp)
target_link_libraries(${PROFILING} PRIVATE ${MATH_LIB})

# Tvorba knihovny "libmath_lib.a"
add_library(${MATH_LIB} STATIC math_lib.cpp)

# Tvorba prikazu "make test"
add_custom_target(test
    COMMAND ./bin/${TEST_SOURCE}
    DEPENDS ${TEST_SOURCE}
    VERBATIM)

# Tvorba prikazu "make run"
add_custom_target(run
    COMMAND ./bin/${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    VERBATIM)
