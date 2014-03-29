#include <QtTest/QtTest>
#include "testperson.h"
#include "testcompany.h"

int main()

{

  TestPerson tP;
  QTest::qExec(&tP);

  TestCompany tC;
  QTest::qExec(&tC);

  return 0;

}
