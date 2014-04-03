TARGET = tst-harbour-log4qtdemo-cppTests

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

QT += testlib

# Note that cppTests do not have any dependency on log4qt headers
# (since engine's headers never include log4qt stuff), but have linking dependency on log4qt binary
LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../../src/engine/ -llog4qtdemo-engine

INCLUDEPATH = ../../src/engine

# TODO: pass path from the higher level project. It is possible to pass it even from .yaml (via .spec and .pro)
QMAKE_RPATHDIR += /usr/share/harbour-log4qtdemo/lib


SOURCES += main.cpp \
    testperson.cpp \
    testcompany.cpp

INSTALLS += target

HEADERS += \
    testperson.h \
    testcompany.h
