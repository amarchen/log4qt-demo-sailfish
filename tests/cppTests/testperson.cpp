#include "testperson.h"
//#include "person.h"

TestPerson::TestPerson(QObject *parent) :
    QObject(parent)
{
}

// You won't probably want to test that low level things in a real project
void TestPerson::emitsNameChangedSignal()
{
//    Person p("John Smith");
//    QSignalSpy nameChangedSpy(p, nameChanged(QString));
//    p.setName("Jane Doe");

//    Q_COMPARE(nameChangedSpy, 1, "Name changed signal should be emitted on name change");
//    Q_COMPARE(nameChangedSpy.takeFirst().arguments.at(0).toString(), "JaneDoe");
}
