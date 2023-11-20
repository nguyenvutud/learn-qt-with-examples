cmake_minimum_required(VERSION 3.5)

project(Qt_signal_interface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

file(GLOB MAIN_SRCS
    "${PROJECT_SOURCE_DIR}/*.cpp"
)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(Qt_signal_interface
  ${MAIN_SRCS}
)
target_link_libraries(Qt_signal_interface Qt5::Core)
