TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    test1002.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    test1002.h

DISTFILES += \
    data1002.txt

