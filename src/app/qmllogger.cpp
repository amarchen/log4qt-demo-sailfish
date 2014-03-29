#include "qmllogger.h"

#include "Logger"


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
