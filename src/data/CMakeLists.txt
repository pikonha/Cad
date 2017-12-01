project(data CXX)

file (GLOB DATA *.h *.cpp)

add_library(data STATIC ${DATA})

target_include_directories(data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
