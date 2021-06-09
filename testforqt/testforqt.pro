#-------------------------------------------------
#
# Project created by QtCreator 2021-06-04T07:28:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testforqt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../dynamic/release/ -lDialogLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../dynamic/debug/ -lDialogLib
else:unix: LIBS += -L$$OUT_PWD/../dynamic/ -lDialogLib

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../dynamic

