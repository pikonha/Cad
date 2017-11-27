project(cmd CXX)

file (GLOB CMD *.h *.cpp)

add_library(cmd STATIC ${CMD})

target_include_directories(cmd PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(cmd domain
						persist
						interface)