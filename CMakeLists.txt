cmake_minimum_required(VERSION 3.9)

project(CAD CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.9.2/msvc2017_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)

add_subdirectory(src/app)
add_subdirectory(src/command)
add_subdirectory(src/domain)
add_subdirectory(src/interface)
add_subdirectory(src/persist)
add_subdirectory(src/manager)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
