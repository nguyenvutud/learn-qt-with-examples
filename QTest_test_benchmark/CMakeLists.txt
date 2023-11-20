cmake_minimum_required(VERSION 3.5)

project(TestBenchmark LANGUAGES CXX)


find_package(Qt5 REQUIRED COMPONENTS Core Gui Test Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestBenchmark tst_testbenchmark.cpp)
add_test(NAME TestBenchmark COMMAND TestBenchmark)

target_link_libraries(TestBenchmark PRIVATE Qt5::Core Qt5::Gui Qt5::Test Qt5::Widgets)

