TEMPLATE = app
TARGET = soundgen
INCLUDEPATH += .

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
SOURCES += mksignal.cpp

maemo* {
    DEFINES += PLAYER_NO_COLOROPTIONS
    }

target.path = ./soundgenbuild/
INSTALLS += target
