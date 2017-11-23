project(persist CXX)

file (GLOB PERSIST *.h *.cpp)

add_library(persist ${PERSIST})

target_include_directories(persist PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")