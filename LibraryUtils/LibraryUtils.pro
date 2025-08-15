#-------------------------------------------------
#
# Project created by QtCreator 2025-08-14T16:13:52
#
#-------------------------------------------------

QT       -= gui

TARGET = LibraryUtils
TEMPLATE = lib
CONFIG += staticlib

SOURCES += libraryutils.cpp

HEADERS += libraryutils.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Add include path to LibraryManagementSystem directory
INCLUDEPATH += $$PWD/../LibraryManagementSystem

CONFIG += c++11
