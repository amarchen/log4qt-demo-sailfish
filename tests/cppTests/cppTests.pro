TARGET = tst-harbour-log4qt-demo-cppTests

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

QT += testlib

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../../src/engine/ -llog4qt-demo-engine

# TODO: pass path from the higher level project
QMAKE_RPATHDIR += /usr/share/harbour-log4qt-demo/lib


SOURCES += main.cpp \
    testperson.cpp \
    testcompany.cpp

INSTALLS += target

INCLUDEPATH = ../../src/engine

HEADERS += \
    testperson.h \
    testcompany.h
