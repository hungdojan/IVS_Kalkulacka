set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} 
    main.cpp
    mainwindow.cpp
    mainwindow.ui
    )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MATH_LIB})
