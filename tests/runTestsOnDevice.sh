#!/bin/bash

# Script for running tests. That's for specifying just one argument in QtCreator's configuration
/usr/bin/tst-harbour-log4qt-demo -input /usr/share/tst-harbour-log4qt-demo

# When you'll get some QML components in the main app, you'll need to import them to the test run
# /usr/bin/tst-harbour-log4qt-demo -input /usr/share/tst-harbour-log4qt-demo -import /usr/share/harbour-log4qt-demo/qml/components
