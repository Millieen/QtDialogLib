#-------------------------------------------------
#
# Project created by QtCreator 2021-06-03T07:38:43
#
#-------------------------------------------------

TARGET = static
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += $$_PRO_FILE_PWD_/../include

SOURCES += $$_PRO_FILE_PWD_/../src/dialoglib.cpp

HEADERS += $$_PRO_FILE_PWD_/../include/dialoglib.h

RESOURCES += \
     $$_PRO_FILE_PWD_/../resources/dialoglib.qrc

TRANSLATIONS += $$_PRO_FILE_PWD_/../resources/zh_CH.ts

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
