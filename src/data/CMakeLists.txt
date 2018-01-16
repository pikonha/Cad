project(data CXX)

set (
	DATA_SOURCES
	Arch.cpp
	Bezier.cpp
	Line.cpp
	File.cpp
	Geometry.cpp
	Point.cpp
	Data.cpp
	)
	
set (
	DATA_HEADERS
	Arch.h
	Bezier.h
	Data.h
	File.h
	FormType.h
	Geometry.h
	Instruction.h
	Line.h
	Point.h
	)

add_library(data STATIC ${DATA_HEADERS} ${DATA_SOURCES})

target_include_directories(data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(data interface)