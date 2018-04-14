TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sudokusolver.cpp \
    sudokucell.cpp

HEADERS += \
    sudokusolver.h \
    sudokucell.h
