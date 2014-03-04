TARGET = tst-harbour-log4qt-demo-cppTests

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

QT += testlib

SOURCES += main.cpp \
    testperson.cpp

INSTALLS += target

INCLUDEPATH = ../../src

HEADERS += \
    testperson.h
