project(persist CXX)

file (GLOB PERSIST *.h *.cpp)

set(CMAKE_AUTOMOC OFF)

add_library(persist STATIC ${PERSIST})

target_include_directories(persist PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")