project(app CXX)

file (GLOB APP *.h *.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/interface")

add_library(app STATIC ${APP})

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1)

target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(app cmd
						domain
						Qt5::Core
						Qt5::Gui
						)