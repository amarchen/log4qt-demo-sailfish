TEMPLATE=lib
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"

TARGET = log4qtdemo-engine

# We could deploy right to final demo app path, but I feel it's better to have more structured INSTALLS
# It should be the app's business which libs to collect where
#TARGETPATH = /usr/share/harbour-log4qtdemo/lib
TARGETPATH = /usr/share/harbour-log4qtdemo-engine
target.path = $$TARGETPATH

QT += quick qml

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include

DEFINES += LOG4QTDEMOENGINE_LIBRARY

#INSTALLS += target

SOURCES += \
    company.cpp \
    person.cpp

HEADERS += \
    company.h \
    person.h

INCLUDEPATH += $$PWD
