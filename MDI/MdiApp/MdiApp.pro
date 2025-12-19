QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    AudioMedia.cpp \
    Song.cpp \
    Audiobook.cpp \
    DialogCreateSong.cpp \
    DialogCreateBook.cpp \
    DialogList.cpp

HEADERS += \
    mainwindow.h \
    AudioMedia.h \
    Song.h \
    Audiobook.h \
    DialogCreateSong.h \
    DialogCreateBook.h \
    DialogList.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
