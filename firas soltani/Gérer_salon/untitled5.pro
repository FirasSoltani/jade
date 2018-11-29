#-------------------------------------------------
#
# Project created by QtCreator 2018-10-21T16:02:11
#
#-------------------------------------------------

QT       += core gui
QT += texttospeech
QT +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled5
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
CONFIG += console

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    user.cpp \
    lights.cpp \
    connect.cpp \
    addlights.cpp \
    modifylight.cpp \
    useredit.cpp \
    adduser.cpp \
    chambers.cpp \
    editchambers.cpp \
    windows.cpp \
    addwindow.cpp

HEADERS += \
        mainwindow.h \
    user.h \
    lights.h \
    connect.h \
    addlights.h \
    modifylight.h \
    useredit.h \
    adduser.h \
    chambers.h \
    editchambers.h \
    windows.h \
    addwindow.h

FORMS += \
        mainwindow.ui \
    addlights.ui \
    modifylight.ui \
    useredit.ui \
    adduser.ui \
    editchambers.ui \
    addwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

//win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lpocketsphinx
//else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lpocketsphinxd
//else:unix: LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lpocketsphinx

//INCLUDEPATH += $$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32
//DEPENDPATH += $$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32

//win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lsphinxbase
//else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lsphinxbased
//else:unix: LIBS += -L$$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32/ -lsphinxbase

//INCLUDEPATH += $$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32
//DEPENDPATH += $$PWD/../../Downloads/pocketsphinx-5prealpha-win32/pocketsphinx/bin/Release/Win32
