QT       += core gui

QT       += core gui sql

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    sign_in.cpp \
    sign_up.cpp \
    sql.cpp \
    user.cpp

HEADERS += \
    game.h \
    mainwindow.h \
    menu.h \
    sign_in.h \
    sign_up.h \
    sql.h \
    user.h

FORMS += \
    game.ui \
    mainwindow.ui \
    menu.ui \
    sign_in.ui \
    sign_up.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arrowW.qrc
