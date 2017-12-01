project (manager CXX)

file ( GLOB MANAGER *.h *.cpp )

add_library(manager STATIC ${MANAGER})

target_include_directories(manager PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(manager cmd
							app)