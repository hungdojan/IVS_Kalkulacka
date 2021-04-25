cmake_minimum_required(VERSION 3.7)

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

# Vypnuti nastaveni instalace GTEST v podslozce
set(INSTALL_GTEST OFF CACHE BOOL "Install gtest library from subproject")

# Podslozky se CMakeLists.txt
add_subdirectory(googletest)
add_subdirectory(gui)

# Tvorba spustitelneho "./test_lib"
# g++ -o ${TEST_SOURCE} ${TEST_SOURCE}.cpp -L. -l${MATH_LIB} -lgtest -lgtest_main
add_executable(${TEST_SOURCE} ${TEST_SOURCE}.cpp)
target_link_libraries(${TEST_SOURCE} PRIVATE ${MATH_LIB} gtest gtest_main)

# Tvorba spustitelneho ./profiling
add_executable(${PROFILING} profiling.cpp)
target_link_libraries(${PROFILING} PRIVATE ${MATH_LIB})

# Tvorba knihovny "libmath_lib.so"
add_library(${MATH_LIB} SHARED math_lib.cpp)
set_target_properties(${MATH_LIB} PROPERTIES
    VERSION "1.0.0"
    SOVERSION "1"
    )

# Instalacni pomocne promenne
set(RESOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(PROJECT_DIR IVS_Kalkulacka)

# Nastaveni informaci o balicku
set(CPACK_GENERATOR                   "DEB")
set(CPACK_PACKAGE_NAME                ${PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT             "Hung Do <xdohun00@stud.fit.vutbr.cz>, 
					                   David Kedra <xkedra00@stud.fit.vutbr.cz>, 
					                   Petr Kolařík <xkolar79@stud.fit.vutbr.cz>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GUI Kalkulacka")
set(CPACK_PACKAGE_VERSION_MAJOR       "1")
set(CPACK_PACKAGE_VERSION_MINOR       "0")
set(CPACK_PACKAGE_VERSION_PATCH       "0")
set(CPACK_SOURCE_GENERATOR            "TGZ")
set(CPACK_SOURCE_IGNORE_FILES         "/build/*")

# Doinstaluje potrebne balicky
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt5widgets5 (>=5.10.0)")
set(CPACK_DEB_COMPONENT_INSTALL ON)

# Instalace knihovny a binarky
install(TARGETS ${PROJECT_NAME} ${MATH_LIB}
    RUNTIME DESTINATION /opt/${PROJECT_DIR}
    ARCHIVE DESTINATION lib
    )

# Instalace do opt slozky
install(FILES ${RESOURCE_PATH}/${PROJECT_NAME} DESTINATION bin)
install(FILES ${RESOURCE_PATH}/${PROJECT_NAME}.desktop DESTINATION share/applications)
install(FILES ${RESOURCE_PATH}/calculator.svg  DESTINATION /opt/${PROJECT_DIR})

# Instalace hlavickovych souboru
install(FILES include/math_lib.h DESTINATION include)

include(CPack)
