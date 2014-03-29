#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDebug>

#if defined(LOG4QTDEMOENGINE_LIBRARY)
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_EXPORT
#else
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_IMPORT
#endif

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

LOG4QTDEMOENGINE_EXPORT QDebug operator<<(QDebug dbg, const Person &person);
LOG4QTDEMOENGINE_EXPORT Log4Qt::LogStream &operator<<(Log4Qt::LogStream rStream,
                                                const Person &rPerson);
#endif // PERSON_H
