TEMPLATE=lib
TARGET = log4qtdemo-engine

# We could deploy right to final demo app path, but I feel it's better to have more structured
# INSTALLS in one place that is actually interested in the final binaries
# It should be the app's business which libs to collect where, so engine won't INSTALLS anything
# TARGETPATH = /usr/share/harbour-log4qtdemo/lib

QT += quick qml

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include

# For using Person, Company and their log streaming (using << syntax) from another binary
DEFINES += LOG4QTDEMOENGINE_LIBRARY

SOURCES += \
    company.cpp \
    person.cpp

HEADERS += \
    company.h \
    person.h

INCLUDEPATH += $$PWD
