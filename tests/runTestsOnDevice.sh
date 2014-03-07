#!/bin/bash

# Script for running tests. That's for specifying just one argument in QtCreator's configuration
/usr/bin/tst-harbour-log4qtdemo -input /usr/share/tst-harbour-log4qtdemo

# When you'll get some QML components in the main app, you'll need to import them to the test run
# /usr/bin/tst-harbour-log4qtdemo -input /usr/share/tst-harbour-log4qtdemo -import /usr/share/harbour-log4qtdemo/qml/components
