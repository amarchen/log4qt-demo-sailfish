TEMPLATE=app
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"
TARGET = harbour-log4qt-demo

# In the bright future this config line will do a lot of stuff to you
CONFIG += sailfishapp

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../engine/ -llog4qt-demo-engine
QMAKE_RPATHDIR += /usr/share/$$TARGET/lib

INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include


engine_and_libs.files += $$OUT_PWD/../../engine/*.so
engine_and_libs.files += $$OUT_PWD/../../ext/Log4Qt/*.so
engine_and_libs.path = /usr/share/$$TARGET/lib

SOURCES += main.cpp

OTHER_FILES = \
# You DO NOT want .yaml be listed here as Qt Creator's editor is completely not ready for multi package .yaml's
#
# Also Qt Creator as of Nov 2013 will anyway try to rewrite your .yaml whenever you change your .pro
# Well, you will just have to restore .yaml from version control again and again unless you figure out
# how to kill this particular Creator's plugin
#    ../rpm/harbour-log4qt-demo.yaml \
    ../rpm/harbour-log4qt-demo.spec \
#    qml/pages/SailCalc.qml \
#    qml/main.qml \
    harbour-log4qt-demo.desktop

INCLUDEPATH += $$PWD/../engine

HEADERS += \
    ../engine/company.h \
    ../engine/person.h

OTHER_FILES += \
    qml/pages/SailCalc.qml \
    qml/main.qml

