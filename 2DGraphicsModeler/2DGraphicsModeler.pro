#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T17:02:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2DGraphicsModeler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        adminlogin.cpp \
        circle.cpp \
        contact.cpp \
        ellipse.cpp \
        line.cpp \
        main.cpp \
        mainwindow.cpp \
        palette.cpp \
        polygon.cpp \
        polyline.cpp \
        rectangle.cpp \
        renderarea.cpp \
        shape.cpp \
        shapebuffer.cpp \
        square.cpp \
        text.cpp

HEADERS += \
        adminlogin.h \
        circle.h \
        contact.h \
        ellipse.h \
        line.h \
        mainwindow.h \
        palette.h \
        palette.h \
        polygon.h \
        polyline.h \
        rectangle.h \
        renderarea.h \
        selection_sort.h \
        shape.h \
        shapebuffer.h \
        square.h \
        text.h \
        vector.h

FORMS += \
        adminlogin.ui \
        contact.ui \
        mainwindow.ui \
        palette.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
