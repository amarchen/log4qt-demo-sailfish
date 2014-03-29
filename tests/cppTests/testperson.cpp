#include "testperson.h"
#include "person.h"

#include <QtTest/QtTest>

TestPerson::TestPerson(QObject *parent) :
    QObject(parent)
{
}

// You won't probably want to test that low level things in a real project
void TestPerson::emitsNameChangedSignal()
{
    Person p("John Smith");
    QSignalSpy nameChangedSpy(&p, SIGNAL(nameChanged(QString)));
    p.setName("Jane Doe");

    QCOMPARE(nameChangedSpy.size(), 1);
    QCOMPARE(nameChangedSpy.takeFirst().at(0).toString(), QString("Jane Doe"));
}
