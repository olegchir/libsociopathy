cmake_minimum_required(VERSION 2.8)
project(libsociopathy)

add_definitions(-DLIBSOCIOPATHY_LIBRARY)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(EXECUTABLE_NAME tester)
set(LIBRARY_NAME    libsociopathy)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_}/bin/)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/
)

file(
    GLOB_RECURSE
    SRC_FILES
    src/*
)

file(
    GLOB_RECURSE
    INCLUDE_FILES
    include/*
)

add_library(
    ${LIBRARY_NAME}
    SHARED
    ${SRC_FILES}
    ${INCLUDE_FILES}
)

add_executable(
    ${EXECUTABLE_NAME}
    testSrc/main.cpp
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    ${LIBRARY_NAME}
)

find_package(Qt5Core REQUIRED)
qt5_use_modules(${LIBRARY_NAME} Core)
