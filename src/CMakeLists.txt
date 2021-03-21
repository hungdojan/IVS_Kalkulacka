cmake_minimum_required(VERSION 3.10)

# Jmeno projektu
project(Kalkulacka)

# -std=c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include hlavickovych souboru ve slozce include
include_directories(include)

# Nastaveni promennych
set(TEST_SOURCE test_lib)
set(MATH_LIB math_lib)

# Tvorba knihoven "libgtest.a" a "libtest_main.a"
add_subdirectory(googletest)

# Tvorba spustitelneho "./test_lib"
# g++ -o ${TEST_SOURCE} ${TEST_SOURCE} -L. -l${MATH_LIB} -lgtest -lgtest_main
add_executable(${TEST_SOURCE} ${TEST_SOURCE}.cpp)
target_link_libraries(${TEST_SOURCE} PRIVATE ${MATH_LIB} gtest gtest_main)

# Tvorba knihovny "libmath_lib.a"
add_library(${MATH_LIB} STATIC math_lib.cpp)

# Tvorba prikazu "make test"
add_custom_target(test
    COMMAND ./${TEST_SOURCE}
    DEPENDS ${TEST_SOURCE}
    VERBATIM)
