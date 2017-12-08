project(interface CXX)

file(GLOB INTERFACE *.h *.cpp)

include_directories("${PROJET_SOURCE_DIR}/src/manager")

add_library(interface STATIC ${INTERFACE})

target_include_directories(interface PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(interface data
							Qt5::Widgets
							Qt5::Gui
							)