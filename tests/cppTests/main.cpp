#include <QtTest/QtTest>
#include "testperson.h"
#include "testcompany.h"

/**
 * No log4qt logs will be printed during the test execution as we do not initialize/configure any logging
 * facilities. Log4qt library will still be called, but without configured logging pipeline
 * all these calls will result in nothing being printed
 * qDebug() and console.log() will still be printed (as intercepting these by log4qt isn't activated as well)
 */

/** This not exactly standard tests invocation makes it possible to run several test cases
 * from one test binary. I find it convenient (at a cost of not having a common summary after
 * all tests are completed in console).
 * Others prefer having one test project and TestCase per binary
 */
int main() {

  TestPerson tP;
  QTest::qExec(&tP);

  TestCompany tC;
  QTest::qExec(&tC);

  return 0;
}
