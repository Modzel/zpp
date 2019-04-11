#-------------------------------------------------
#
# Project created by QtCreator 2019-03-04T18:41:05
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZPP_PROJKET
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    block.cpp \
    gamemenu.cpp \
    puzzlegame.cpp \
    settingsmenu.cpp \
    gamesettings.cpp \
    board.cpp \
    boardfactory.cpp

HEADERS += \
        mainwindow.h \
    block.h \
    gamemenu.h \
    puzzlegame.h \
    gamemenuitems.h \
    settingsmenu.h \
    gamesettings.h \
    board.h \
    boardfactory.h \


FORMS += \
        mainwindow.ui \
    gamemenu.ui \
    settingsmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dzwiek.wav
