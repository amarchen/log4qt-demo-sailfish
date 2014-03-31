#include "person.h"
#include "Logger"
#include <QDebug>
#include "LogStream"

LOG4QT_DECLARE_STATIC_LOGGER(logger, Person)

Person::Person(const QString& name, QObject *parent) :
    QObject(parent)
{
    setName(name);

    logger()->debug("Person created with name %1", name);

    // I don't know why, but sometimes this message is missing from exactly syslog appender
    // when object is instantiated from QML (and with empty name)
    // Previous message (with %1) still prints fine
    //
    // TODO: Figure out what sort of magic happens there
    // Must be somehow related to default function parameter instantiation
    // ..but why only syslog appender is affected?
    logger()->info() << "Person created, name is " << name;
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(QString arg)
{

    // For performance reasons it is better to use %1 syntax whenever you are not too lazy to do so
    // Then arg is not converted to string unless it is needed
    // (can be not needed if whole INFO level is disabled)
    logger()->info("setName for %1", arg);

    // Streaming syntax is a little easier to type, but less efficient
    // logger()->info() << "setName for " << arg;
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}

// QDebug and log4qt's streaming support
// Unfortunately you need to have two functions to support both
LOG4QTDEMOENGINE_EXPORT QDebug operator<<(QDebug dbg, const Person &person) {
    dbg.nospace() << "(qD: " << person.name() << ")";
    return dbg.maybeSpace();
}

LOG4QTDEMOENGINE_EXPORT Log4Qt::LogStream &operator<<(Log4Qt::LogStream rStream,
                                                const Person &rPerson) {
    rStream << "(lS: " << rPerson.name() << ")";
    return rStream;
}
