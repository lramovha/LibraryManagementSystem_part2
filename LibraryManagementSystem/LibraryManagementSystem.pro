#-------------------------------------------------
#
# Project created by QtCreator 2025-08-14T16:11:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManagementSystem
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    libraryitem.cpp \
    book.cpp \
    magazine.cpp

HEADERS  += mainwindow.h \
    libraryitem.h \
    book.h \
    magazine.h

FORMS    += mainwindow.ui

# Link to the built LibraryUtils library
LIBS += -L$$PWD/../build-LibraryUtils-Desktop_Qt_5_3_0_MinGW_32bit-Release/release -lLibraryUtils

INCLUDEPATH += $$PWD/../LibraryUtils
DEPENDPATH += $$PWD/../LibraryUtils

# Enable C++11 support
CONFIG += c++11
