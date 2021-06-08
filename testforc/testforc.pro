TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../dynamic/release/ -ldynamic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../dynamic/debug/ -ldynamic
else:unix: LIBS += -L$$OUT_PWD/../dynamic/ -ldynamic

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../dynamic
