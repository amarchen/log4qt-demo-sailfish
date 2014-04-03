#Log4Qt usage demo

## Description/docs
- Lots of comments in the code and project files
- For more details see this [blog post at codingsubmarine](http://www.codingsubmarine.com/log4qt-for-jolla-sailfish-os-and-in-general). Later it is to be integrated to this blog post
- This project is for [Jolla Sailfish OS](http://sailfishos.org), but not so much is Sailfish-specific in fact, same practices should work for all things Qt as well.

## Projects inside
- There are two completely independent projects in the repository. Main contains log4qt, engine, app itself, cppTests, qmlTests. Another one called increasedLoggingPackage is a fake "app" that you send to the user in trouble. Once he installs it, main app starts generating way more logs for you to analyze.
- Sailfish SDK sometimes misbehaves while building RPMs is you open both projects in Qt Creator simultaneously, so care to have only one of them opened.


## Un(license)
- Log4Qt library (fetched in via git subtree) is licensed under Apache License Version 2.0
- The rest of project is published under public domain (un)license, i.e. you can even resell this project if you like. It will be kind of you to mention it if you use it though. See legal details in the file UNLICENSE.txt
- By submitting a pull request you agree that it will be treated under the same public domain unlicense

## TODOs
There are a number TODOs in the code that you are free to take on. Here are some of them
- Migrate docs from [blog post at codingsubmarine](http://www.codingsubmarine.com/log4qt-for-jolla-sailfish-os-and-in-general) to here (Artem the post author grants public domain license on the post text and images)
  - and make them even better
- main.cpp: Implement replacing of $XDG_CACHE_HOME (and other vars?) with the proper values before configuring log4qt (and in some stand-alone function?)
- main.cpp: Extract this manual logging setup and .conf-based setup into the separate methods and just comment out the call to one of them
- main.cpp: Move "Ivan Kuznetsov" object streaming exampple to some other place. At least to a stand-alone function
- qmllogger.cpp: Cache the logger pointer after it is retrieved once
- BrowserPage.qml:4  Add pulley menu with "Open in a browser". Note that logging demo sometimes opens .log file, Qt.openUrlExternally won't work for these (maybe don't have pulley menu for it then)
- Study if it's possible to log from QML as much as object streaming in c++ allows for(using << syntax)
- company.cpp: Create macros for logging messages with line numbers and function names and propose them for merging into Log4Qt project
- person.cpp: Figure out why logging exactly empty name string exactly to syslog doesn't work there
cppTests.pro: Pass path from the higher level project. It is possible to pass it even from .yaml (via .spec and .pro)
