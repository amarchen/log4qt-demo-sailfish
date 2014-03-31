TEMPLATE = app

TARGET = tst-harbour-log4qtdemo-qmlTests

# For registering engine's and app's classes
QT += quick qml

CONFIG += qmltestcase

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET

# QML files and folders
qml.path = $$DEPLOYMENT_PATH
qml.files = *.qml

# Shell script for running both c++ and QML tests. It doesn't really matter which project you deploy
# it from. I find it more natural to deploy from the project that builds last.. for no real reason
extra.path = $$DEPLOYMENT_PATH
extra.files = ../runTestsOnDevice.sh

# defining QUICK_TEST_SOURCE_DIR here doesn't work, QtCreator keeps injecting another definition to command line (from CONFIG += qmltestcase ?)
#DEFINES += QUICK_TEST_SOURCE_DIR=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"
DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

# Log4qt headers are only needed for app's qmllogger.cpp actually
# In a production project you can get rid of it e.g. by making qmllogger a part of engine lib
# Or by proposing something like QmlLogger to become a part of log4qt :)
INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include
INCLUDEPATH += ../../src/engine
INCLUDEPATH += ../../src/app

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../../src/engine/ -llog4qtdemo-engine
QMAKE_RPATHDIR += /usr/share/harbour-log4qtdemo/lib


# Compiling QML logger straight from app sources
# Could be not the ideal way maybe, but that's just a small utility class that we are not going to test anyway
SOURCES += main.cpp \
    ../../src/app/qmllogger.cpp

# C++ headers
HEADERS += ../../src/app/qmllogger.h

INSTALLS += target qml extra

OTHER_FILES += \
    tst_mainPage.qml



