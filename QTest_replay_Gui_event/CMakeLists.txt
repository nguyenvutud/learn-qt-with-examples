cmake_minimum_required(VERSION 3.5)

project(replaying_event LANGUAGES CXX)


find_package(Qt5 REQUIRED COMPONENTS Core Gui Test Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(replaying_event tst_replaying_event.cpp)
add_test(NAME replaying_event COMMAND replaying_event)

target_link_libraries(replaying_event PRIVATE Qt5::Core Qt5::Gui Qt5::Test Qt5::Widgets)

