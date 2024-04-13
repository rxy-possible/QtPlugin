QT += core

TEMPLATE = lib

TARGET = $$qtLibraryTarget(PluginDemo)

CONFIG += c++11 plugin

TARGET = PluginDemo

DESTDIR = ../plugins

EXAMPLE_FILES = plugindemo.json

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        plugindemo.cpp \
        plugindemo.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    plugindemo.h \
    plugindemo.h \
    plugininterface.h \
    plugininterface.h
