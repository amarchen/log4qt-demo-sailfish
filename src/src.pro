TEMPLATE=app
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"
TARGET = harbour-log4qt-demo

# In the bright future this config line will do a lot of stuff to you
CONFIG += sailfishapp

#Log4Qt
LIBS += -L$$OUT_PWD/../ext/Log4Qt/ -llog4qt
INCLUDEPATH += ../ext/Log4Qt/src ../ext/Log4Qt/deploy/include
QMAKE_RPATHDIR += /usr/share/harbour-log4qt-trial/lib

log4qt_library.files=$$OUT_PWD/../ext/Log4Qt/liblog4qt.*
log4qt_library.path=/usr/share/$$TARGET/lib

INSTALLS += log4qt_library


SOURCES += main.cpp

OTHER_FILES = \
# You DO NOT want .yaml be listed here as Qt Creator's editor is completely not ready for multi package .yaml's
#
# Also Qt Creator as of Nov 2013 will anyway try to rewrite your .yaml whenever you change your .pro
# Well, you will just have to restore .yaml from version control again and again unless you figure out
# how to kill this particular Creator's plugin
#    ../rpm/harbour-log4qt-demo.yaml \
    ../rpm/harbour-log4qt-demo.spec \
    qml/pages/SailCalc.qml \
    qml/main.qml

INCLUDEPATH += $$PWD
