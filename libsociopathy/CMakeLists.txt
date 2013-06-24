cmake_minimum_required(VERSION 2.8)
project(libsociopathy)
add_definitions(-DLIBSOCIOPATHY_LIBRARY)

#enable C++x11
add_definitions(-std=c++11)
list( APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

#apply platform-specific flags
if (UNIX)
  message(status "Setting GCC flags")
  set(APPEND CMAKE_CXX_FLAGS "-fexceptions -g -Wall")
else()
  message(status "Setting MSVC flags")
  set(APPEND CMAKE_CXX_FLAGS "/EHc-")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(EXECUTABLE_NAME tester)
set(LIBRARY_NAME    libsociopathy)

#link against Boost library
#http://cpprocks.com/using-cmake-to-build-a-cross-platform-project-with-a-boost-dependency/
add_definitions(-DBOOST_ALL_DYN_LINK)
#add_definitions(-DBOOST_ALL_NO_LIB)
find_package(Boost COMPONENTS program_options REQUIRED)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)


#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_}/bin/)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${Boost_INCLUDE_DIR}
)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/
    ${Boost_LIBRARY_DIRS}
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
    ${Boost_LIBRARIES}
)

#link against Qt5
find_package(Qt5Core REQUIRED)
qt5_use_modules(${LIBRARY_NAME} Core)
