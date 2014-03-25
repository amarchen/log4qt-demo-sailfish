TEMPLATE=app
# The name of your app binary (and it's better if you think it is the whole app name as it's referred to many times)
# Must start with "harbour-"
TARGET = harbour-log4qtdemo

# In the bright future this config line will do a lot of stuff to you
CONFIG += sailfishapp
documentation.CONFIG = no_check_exist

LIBS += -L$$OUT_PWD/../../ext/Log4Qt/ -llog4qt
LIBS += -L$$OUT_PWD/../engine/ -llog4qtdemo-engine
QMAKE_RPATHDIR += /usr/share/$$TARGET/lib

INCLUDEPATH += ../../ext/Log4Qt/src ../../ext/Log4Qt/deploy/include

# per http://qt-project.org/faq/answer/how_to_deal_correctly_with_project_files_that_should_generate_a_debug_and_r
# except that build_pass seems to be not needed/working for Sailfish OS
#
# Copying config file is per http://www.qtcentre.org/threads/49545-It-is-possible-to-rename-file-with-qmake?highlight=
# Should work on Windows for Sailfish builds as they use own build machine anyway.
# If you port this example to something more general, care about adjustments for Windows
CONFIG(debug, debug|release) {
    message(Debug build)
    log4qt_demo_config.extra = cp $$PWD/../../log4qt-debug.conf $$OUT_PWD/../../log4qt.conf
}
else {
    message(Release build)
    log4qt_demo_config.extra = cp $$PWD/../../log4qt-release.conf $$OUT_PWD/../../log4qt.conf
}
log4qt_demo_config.files = $$OUT_PWD/../../log4qt.conf
log4qt_demo_config.path = /usr/share/$$TARGET

# Covers all versions of .so files
log4qt_lib.files += $$OUT_PWD/../../ext/Log4Qt/*.s*
log4qt_lib.path = /usr/share/$$TARGET/lib
log4qt_demo_engine.files += $$OUT_PWD/../engine/*.s*
log4qt_demo_engine.path = /usr/share/$$TARGET/lib

INSTALLS += log4qt_lib log4qt_demo_engine log4qt_demo_config

SOURCES += main.cpp \
    qmllogger.cpp

OTHER_FILES = \
# You DO NOT want .yaml be listed here as Qt Creator's editor is completely not ready for multi package .yaml's
#
# Also Qt Creator as of Nov 2013 will anyway try to rewrite your .yaml whenever you change your .pro
# Well, you will just have to restore .yaml from version control again and again unless you figure out
# how to kill this particular Creator's plugin
#    ../rpm/harbour-log4qtdemo.yaml \
    ../rpm/harbour-log4qtdemo.spec \
#    ../../log4qt.conf \
    ../../log4qt-debug.conf \
    ../../log4qt-release.conf \
    harbour-log4qtdemo.desktop \
    qml/pages/MainPage.qml \
    qml/main.qml

INCLUDEPATH += $$PWD/../engine

HEADERS += \
    ../engine/company.h \
    ../engine/person.h \
    qmllogger.h
