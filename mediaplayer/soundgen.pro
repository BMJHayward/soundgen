QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
TARGET = soundgen
INCLUDEPATH += .
INCLUDEPATH += ../noises

QT += network xml multimedia multimediawidgets widgets

# Input
HEADERS += histogramwidget.h \
           player.h \
           playercontrols.h \
           playlistmodel.h \
           videowidget.h
SOURCES += histogramwidget.cpp \
           main.cpp \
           player.cpp \
           playercontrols.cpp \
           playlistmodel.cpp \
           videowidget.cpp
SOURCES += ../noises/mksignal.cpp

maemo* {
    DEFINES += PLAYER_NO_COLOROPTIONS
    }

target.path = ./soundgenbuild/
INSTALLS += target
