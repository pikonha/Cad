#-------------------------------------------------
#
# Project created by QtCreator 2018-01-17T12:34:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCad
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    app/App.h \
    command/Cmd.h \
    command/CmdClearAllItems.h \
    command/CmdClearLastItem.h \
    command/CmdClose.h \
    command/CmdCloseTab.h \
    command/CmdDiscard.h \
    command/CmdIdle.h \
    command/CmdLoad.h \
    command/CmdNewFile.h \
    command/CmdSave.h \
    command/CmdSetCurrentFile.h \
    command/CmdSetZoom.h \
    command/MainCmd.h \
    command/MainCmdArch.h \
    command/MainCmdBezier.h \
    command/MainCmdLine.h \
    data/Arch.h \
    data/Bezier.h \
    data/Data.h \
    data/File.h \
    data/FormType.h \
    data/Geometry.h \
    data/Instruction.h \
    data/Line.h \
    data/Point.h \
    interface/MainScreen.h \
    interface/NewFileWidget.h \
    interface/View.h \
    manager/Manager.h

SOURCES += \
    app/App.cpp \
    app/Master.cpp \
    command/CmdClearAllItems.cpp \
    command/CmdClearLastItem.cpp \
    command/CmdClose.cpp \
    command/CmdCloseTab.cpp \
    command/CmdDiscard.cpp \
    command/CmdLoad.cpp \
    command/CmdNewFile.cpp \
    command/CmdSave.cpp \
    command/CmdSetCurrentFile.cpp \
    command/CmdSetZoom.cpp \
    command/MainCmd.cpp \
    command/MainCmdArch.cpp \
    command/MainCmdBezier.cpp \
    command/MainCmdLine.cpp \
    data/Arch.cpp \
    data/Bezier.cpp \
    data/Data.cpp \
    data/File.cpp \
    data/Geometry.cpp \
    data/Line.cpp \
    data/Point.cpp \
    interface/MainScreen.cpp \
    interface/View.cpp \
    interface/NewFileWidget.cpp \
    manager/Manager.cpp

RESOURCES += \
    resources.qrc
