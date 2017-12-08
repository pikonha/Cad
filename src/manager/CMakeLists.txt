project (manager CXX)

file ( GLOB MANAGER *.h *.cpp )

include_directories("${PROJECT_SOURCE_DIR}/src/interface")

add_library(manager STATIC ${MANAGER})

target_include_directories(manager PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(manager cmd)