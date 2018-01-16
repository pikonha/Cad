project(app CXX)

set (
	APP_SOURCES
	App.cpp
	Master.cpp
	)
	
set (
	APP_HEADERS
	App.h
	)

add_executable(app ${APP_HEADERS} ${APP_SOURCES})

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1)

target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(app manager
						data
						interface
						Qt5::Core
						Qt5::Widgets
						)