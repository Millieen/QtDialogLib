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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../static/release/ -lstatic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../static/debug/ -lstatic
else:unix: LIBS += -L$$OUT_PWD/../static/ -lstatic

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../static

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/release/static.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/debug/static.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../static/libstatic.a
