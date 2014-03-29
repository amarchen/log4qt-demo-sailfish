TEMPLATE = app

# The name of your app
TARGET = tst-harbour-log4qtdemo-qmlTests

# For registering engine's and app's classes
QT += quick qml

CONFIG += qmltestcase

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

extra.path = $$DEPLOYMENT_PATH
extra.files = ../runTestsOnDevice.sh

# defining QUICK_TEST_SOURCE_DIR here doesn't work QtCreator keeps injecting another definition to command line (from CONFIG += qmltestcase ?)
#DEFINES += QUICK_TEST_SOURCE_DIR=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"
DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

# C++ sources
# Compiling QML logger straight from app sources
# Could be not the ideal way maybe, but that's a small utility class not for testing anyway
SOURCES += main.cpp \
    ../../src/app/qmllogger.cpp #\
#    fakeqmllogger.cpp

INCLUDEPATH += ../../src/engine
INCLUDEPATH += ../../src/app
INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../../src/engine/ -llog4qtdemo-engine
QMAKE_RPATHDIR += /usr/share/harbour-log4qtdemo/lib


# C++ headers
HEADERS += ../../src/app/qmllogger.h

INSTALLS += target qml extra

# QML files and folders
qml.files = *.qml

OTHER_FILES += \
    tst_mainPage.qml



