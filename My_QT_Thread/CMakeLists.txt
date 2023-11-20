cmake_minimum_required(VERSION 3.5)

project(My_QT_Thread LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(My_QT_Thread
  main.cpp mythread.cpp myworker.cpp
)

include_directories(My_QT_Thead "mythread.h" "myworker.h")
target_link_libraries(My_QT_Thread Qt5::Core)
