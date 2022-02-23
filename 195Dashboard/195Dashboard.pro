#-------------------------------------------------
#
# Project created by QtCreator 2022-02-13T16:39:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 195Dashboard
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


SOURCES += \
        main.cpp \
        dashboardwindow.cpp \

HEADERS += \
        dashboardwindow.h \
        oscpp/detail/endian.hpp \
        oscpp/detail/host.hpp \
        oscpp/detail/stream.hpp \
        oscpp/client.hpp \
        oscpp/error.hpp \
        oscpp/print.hpp \
        oscpp/server.hpp \
        oscpp/types.hpp \
        oscpp/util.hpp \

FORMS += \
        dashboardwindow.ui
