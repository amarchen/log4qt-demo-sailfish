#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDebug>

#if defined(LOG4QTDEMOENGINE_LIBRARY)
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_EXPORT
#else
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_IMPORT
#endif


// While we do use Log4Qt namespace, everything is forward declared here, no log4qt header dependency is created
// Final app will still need to link to log4qt and use some of its headers (for logging initizalization at least)
// So decide yourself how much you want to avoid extra header dependencies.
// If you are fine with it, it can be more convenient to declare class logger via LOG4QT_DECLARE_QCLASS_LOGGER
// right after Q_OBJECT line
namespace Log4Qt {
    class LogStream;
}

class LOG4QTDEMOENGINE_EXPORT Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Person(const QString& name = QString(), QObject* parent = 0);

    QString name() const;

signals:
    void nameChanged(QString arg);

public slots:
    void setName(QString arg);

private:
    QString m_name;

};

// While log4qt's and and qDebug's streaming syntax is the same <<, unfortunately you
// have to create two different methods if you want to support streaming to both
// LOG4QTDEMOENGINE_EXPORT is needed if you want to do it from another binary
LOG4QTDEMOENGINE_EXPORT QDebug operator<<(QDebug dbg, const Person &person);
LOG4QTDEMOENGINE_EXPORT Log4Qt::LogStream &operator<<(Log4Qt::LogStream rStream,
                                                const Person &rPerson);
#endif // PERSON_H
