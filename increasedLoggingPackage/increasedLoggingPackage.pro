TARGET = increasedLoggingPackage

CONFIG += sailfishapp

SOURCES += src/increasedLoggingPackage.cpp

conf_file.files = log4qt.conf
conf_file.path = /home/nemo/.config/harbour-log4qtdemo

INSTALLS += conf_file

OTHER_FILES += qml/increasedLoggingPackage.qml \
    qml/pages/FirstPage.qml \
    rpm/increasedLoggingPackage.spec \
    increasedLoggingPackage.desktop \
    log4qt.conf

