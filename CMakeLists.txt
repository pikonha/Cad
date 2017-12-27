cmake_minimum_required(VERSION 3.9)

project(CAD CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.9.2/msvc2017_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)
		
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Users/lucas.picollo/Documents/Projects/QT-Cad/boost_1_66_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Users/lucas.picollo/Documents/Projects/QT-Cad/boost_1_66_0/libs")

find_package(Boost)
		
if(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
   ADD_DEFINITIONS( "-DHAS_BOOST" )
 endif()

add_subdirectory(src/app)
add_subdirectory(src/command)
add_subdirectory(src/interface)
add_subdirectory(src/manager)
add_subdirectory(src/data)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
