#include <QtQuickTest/quicktest.h>
#include <QtQuick>

#include "person.h"
#include "company.h"
#include "qmllogger.h"

/**
 * No log4qt logs will be printed during the test execution as we do not initialize/configure any logging
 * facilities. Log4qt library will still be called, but without configured logging pipeline
 * all these calls will result in nothing being printed
 * qDebug() and console.log() will still be printed (as intercepting these by log4qt isn't activated as well)
 */

// That is just the same what QUICK_TEST_MAIN(Log4QtDemoTestSet) is doing except that
// we register QML objects first
int main(int argc, char **argv) {
    qmlRegisterType<Person>("harbour.log4qtdemo", 0, 1, "Person");
    qmlRegisterType<Company>("harbour.log4qtdemo", 0, 1, "Company");
    qmlRegisterType<QmlLogger>("harbour.log4qtdemo", 0, 1, "Logger");

    return quick_test_main(argc, argv, "Log4QtDemoTestSet", QUICK_TEST_SOURCE_DIR);
}
