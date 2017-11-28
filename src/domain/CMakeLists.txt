project(domain CXX)

file(GLOB DOMAIN *.h *.cpp)

add_library(domain STATIC ${DOMAIN})

target_include_directories(domain PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(domain Qt5::Widgets)