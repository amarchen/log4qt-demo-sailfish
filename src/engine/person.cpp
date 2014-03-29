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

    // Streaming like this doesn't work for e.g. systemlogappender
//    logger()->info() << "Person created, name is " << name;
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

LOG4QTDEMOENGINE_EXPORT QDebug operator<<(QDebug dbg, const Person &person) {
    dbg.nospace() << "(" << person.name() << ")";
    return dbg.maybeSpace();
}

LOG4QTDEMOENGINE_EXPORT Log4Qt::LogStream &operator<<(Log4Qt::LogStream rStream,
                                                const Person &rPerson) {
    rStream << "(ls: " << rPerson.name() << ")";
    return rStream;
}
