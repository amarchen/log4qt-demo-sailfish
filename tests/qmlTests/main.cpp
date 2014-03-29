#include <QtQuickTest/quicktest.h>
#include <QtQuick>

#include "person.h"
#include "company.h"
#include "qmllogger.h"

// SailCalcTestSet is just a convenient name for reports - not linked to any of the main project entities
//QUICK_TEST_MAIN(Log4QtDemoTestSet)
int main(int argc, char **argv) {
    qmlRegisterType<Person>("harbour.log4qtdemo", 0, 1, "Person");
    qmlRegisterType<Company>("harbour.log4qtdemo", 0, 1, "Company");
    qmlRegisterType<QmlLogger>("harbour.log4qtdemo", 0, 1, "Logger");

    return quick_test_main(argc, argv, "Log4QtDemoTestSet", QUICK_TEST_SOURCE_DIR);
}
