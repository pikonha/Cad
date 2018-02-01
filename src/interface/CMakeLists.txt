project(interface CXX)

set (
	INTERFACE_SOURCES
	NewFileWidget.cpp
	MainScreen.cpp
	View.cpp
)
	
set (
	INTERFACE_HEADERS
	NewFileWidget.h
	MainScreen.h
	View.h
)	

include_directories("${PROJECT_SOURCE_DIR}/src/manager")

add_library(interface STATIC ${INTERFACE_HEADERS} ${INTERFACE_SOURCES})

target_include_directories(interface PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(interface Qt5::Gui
							Qt5::Widgets							
							)