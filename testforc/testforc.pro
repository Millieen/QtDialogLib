TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -L$$QMAKE_LIBDIR_QT -lQtGui -lQtCore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../static/release/ -lDialogLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../static/debug/ -lDialogLib
else:unix: LIBS += -L$$OUT_PWD/../static/ -lDialogLib

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../static

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/release/DialogLib.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/debug/DialogLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../static/libDialogLib.a

