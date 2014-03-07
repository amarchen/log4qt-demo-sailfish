TEMPLATE=app
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"
TARGET = harbour-log4qtdemo

# In the bright future this config line will do a lot of stuff to you
CONFIG += sailfishapp

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../engine/ -llog4qtdemo-engine
QMAKE_RPATHDIR += /usr/share/$$TARGET/lib

INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include

message($$OUT_PWD)
message($$OUT_PWD/../../ext/Log4Qt/*.s*)
message($$OUT_PWD/../engine/*.s*)
# Covers all versions of .so files
log4qt_lib.files += $$OUT_PWD/../../ext/Log4Qt/*.s*
log4qt_lib.path = /usr/share/$$TARGET/lib
log4qt_demo_engine.files += $$OUT_PWD/../engine/*.s*
log4qt_demo_engine.path = /usr/share/$$TARGET/lib

INSTALLS += log4qt_lib log4qt_demo_engine

SOURCES += main.cpp

OTHER_FILES = \
# You DO NOT want .yaml be listed here as Qt Creator's editor is completely not ready for multi package .yaml's
#
# Also Qt Creator as of Nov 2013 will anyway try to rewrite your .yaml whenever you change your .pro
# Well, you will just have to restore .yaml from version control again and again unless you figure out
# how to kill this particular Creator's plugin
#    ../rpm/harbour-log4qtdemo.yaml \
    ../rpm/harbour-log4qtdemo.spec \
#    qml/pages/SailCalc.qml \
#    qml/main.qml \
    harbour-log4qtdemo.desktop \
    qml/pages/MainPage.qml

INCLUDEPATH += $$PWD/../engine

HEADERS += \
    ../engine/company.h \
    ../engine/person.h

OTHER_FILES += \
    qml/main.qml

