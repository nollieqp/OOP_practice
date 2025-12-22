QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Вмикаємо консоль для налагодження (щоб бачити qDebug)
# CONFIG += console
# CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    AudioMedia.cpp \
    Song.cpp \
    Audiobook.cpp \
    DialogCreateSong.cpp \
    DialogCreateBook.cpp \
    DialogList.cpp \
    SqliteDBManager.cpp \

HEADERS += \
    mainwindow.h \
    AudioMedia.h \
    Song.h \
    Audiobook.h \
    DialogCreateSong.h \
    DialogCreateBook.h \
    DialogList.h \
    SqliteDBManager.h \

FORMS += \
    DialogCreateBook.ui \
    DialogCreateSong.ui \
    dialoglist.ui \
    mainwindow.ui \
    DialogCreateSong.ui \
    DialogCreateBook.ui \
    DialogList.ui

# Стандартні правила розгортання
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
