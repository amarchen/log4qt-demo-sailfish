#include "testcompany.h"
#include "company.h"

#include <QtTest/QtTest>

TestCompany::TestCompany(QObject *parent) :
    QObject(parent)
{
}

// You won't probably want to test that low level things in a real project
void TestCompany::emitsNameChangedSignal()
{
    Company c("Nokia");
    QSignalSpy nameChangedSpy(&c, SIGNAL(nameChanged(QString)));
    c.setName("Microsoft Hardware");

    QCOMPARE(nameChangedSpy.size(), 1);
    QCOMPARE(nameChangedSpy.takeFirst().at(0).toString(), QString("Microsoft Hardware"));
}

