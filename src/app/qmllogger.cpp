#include "qmllogger.h"

#include "Logger"

// All the logging calls here first retrive logger by name
// In production code you may like to cache the obtained logger pointer to avoid constant lookups
// TODO: Cache the logger pointer after it is retrieved once
QmlLogger::QmlLogger(QObject *parent) :
    QObject(parent)
{
}

void QmlLogger::trace(const QString &rMessage) const
{
    Log4Qt::Logger::logger(m_name.toLatin1().constData())->debug(rMessage);
}

void QmlLogger::debug(const QString &rMessage) const
{
    Log4Qt::Logger::logger(m_name.toLatin1().constData())->debug(rMessage);
}

void QmlLogger::info(const QString &rMessage) const
{
    Log4Qt::Logger::logger(m_name.toLatin1().constData())->debug(rMessage);
}

void QmlLogger::error(const QString &rMessage) const
{
    Log4Qt::Logger::logger(m_name.toLatin1().constData())->debug(rMessage);
}

void QmlLogger::fatal(const QString &rMessage) const
{
    Log4Qt::Logger::logger(m_name.toLatin1().constData())->debug(rMessage);
}

QString QmlLogger::name() const
{
    return m_name;
}

void QmlLogger::setName(QString arg)
{
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}
