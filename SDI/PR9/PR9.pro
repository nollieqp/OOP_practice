QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Вимикаємо попередження про застарілі функції (необов'язково)
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    song.cpp

HEADERS += \
    mainwindow.h \
    song.h

FORMS += \
    mainwindow.ui

# Правила для деплою (стандартні)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
