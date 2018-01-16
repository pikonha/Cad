project(cmd CXX)

set (
	CMD_SOURCES
	CmdClearAllItems.cpp
	CmdClearLastItem.cpp
	CmdClose.cpp
	CmdCloseTab.cpp
	CmdDiscard.cpp
	CmdLoad.cpp
	CmdNewFile.cpp
	CmdSave.cpp
	CmdSetCurrentFile.cpp
	CmdSetZoom.cpp
	MainCmd.cpp
	MainCmdArch.cpp
	MainCmdBezier.cpp
	MainCmdLine.cpp
	)
	
set (
	CMD_HEADERS
	Cmd.h
	CmdClearAllItems.h
	CmdClearLastItem.h
	CmdClose.h
	CmdCloseTab.h
	CmdDiscard.h
	CmdIdle.h
	CmdLoad.h
	CmdNewFile.h
	CmdSave.h
	CmdSetCurrentFile.h
	CmdSetZoom.h
	MainCmd.h
	MainCmdArch.h
	MainCmdBezier.h
	MainCmdLine.h
	)
add_library(cmd STATIC ${CMD_HEADERS} ${CMD_SOURCES})

target_include_directories(cmd PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(cmd interface
						data)