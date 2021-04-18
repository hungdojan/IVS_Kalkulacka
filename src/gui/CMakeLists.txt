set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB SOURCE *.cpp *.h *.ui)
add_executable(${PROJECT_NAME} 
    ${SOURCE}
    )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MATH_LIB})
