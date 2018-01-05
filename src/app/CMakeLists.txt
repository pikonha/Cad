project(app CXX)

file (GLOB APP *.h *.cpp)

add_executable(app ${APP})

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1)

target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(app manager
						data
						interface
						Qt5::Core
						Qt5::Widgets
						)