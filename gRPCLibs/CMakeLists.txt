cmake_minimum_required(VERSION 3.5)

project(gRPCLibs LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core LinguistTools REQUIRED)

set(TS_FILES gRPCLibs_en_US.ts)

add_library(gRPCLibs SHARED
  gRPCLibs_global.h
  grpclibs.cpp
  grpclibs.h
  ${TS_FILES}
)

target_link_libraries(gRPCLibs PRIVATE Qt5::Core)

target_compile_definitions(gRPCLibs PRIVATE GRPCLIBS_LIBRARY)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
