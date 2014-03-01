#include "person.h"

#include <QDebug>

Person::Person(const QString& name, QObject *parent) :
    QObject(parent)
{
    setName(name);
    logger()->debug("Person created with name %1", name);
    logger()->info() << "Person created, name is " << name;
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(QString arg)
{
    logger()->info("setName for %1", arg);
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}
