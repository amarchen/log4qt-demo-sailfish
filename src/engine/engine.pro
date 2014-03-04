TEMPLATE=lib
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"

TARGET = log4qt-demo-engine
TARGETPATH = /usr/share/harbour-log4qt-demo/lib
target.path = $$TARGETPATH

QT += quick qml

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include
QMAKE_RPATHDIR += /usr/share/$$TARGET/lib

DEFINES += LOG4QTDEMOENGINE_LIBRARY

INSTALLS += target

SOURCES += \
    company.cpp \
    person.cpp

HEADERS += \
    company.h \
    person.h

INCLUDEPATH += $$PWD
