cmake_minimum_required(VERSION 3.5)

project(CPlusplus_MutableKeyword LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(CPlusplus_MutableKeyword
  main.cpp
)
target_link_libraries(CPlusplus_MutableKeyword Qt5::Core)
