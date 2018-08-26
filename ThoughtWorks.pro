TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += ./src/maze.cpp main.cpp

HEADERS +=./include ./include/parseline.h \
            ./include/maze.h

