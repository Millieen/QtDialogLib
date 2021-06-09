#-------------------------------------------------
#
# Project created by QtCreator 2021-06-03T06:59:19
#
#-------------------------------------------------

TARGET = dynamic
TEMPLATE = lib

DEFINES += DYNAMIC_LIBRARY

TARGET = DialogLib

INCLUDEPATH += $$_PRO_FILE_PWD_/../include

SOURCES += $$_PRO_FILE_PWD_/../src/dialoglib.cpp \
    $$_PRO_FILE_PWD_/../src/messagedialog.cpp

HEADERS += $$_PRO_FILE_PWD_/../include/dialoglib.h \
    $$_PRO_FILE_PWD_/../src/messagedialog.h

FORMS += \
    $$_PRO_FILE_PWD_/../src/messagedialog.ui

TRANSLATIONS += $$_PRO_FILE_PWD_/../resources/zh_CH.ts

RESOURCES += \
     $$_PRO_FILE_PWD_/../resources/dialoglib.qrc

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

