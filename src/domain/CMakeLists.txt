project(domain CXX)

file(GLOB DOMAIN *.h *.cpp)

set(CMAKE_AUTOMOC OFF)

add_library(domain STATIC ${DOMAIN})

target_include_directories(domain PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
