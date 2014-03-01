#ifndef PERSON_H
#define PERSON_H

#include <QObject>

#include "Logger"
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Person(const QString& name, QObject* parent = 0);

    QString name() const;

signals:
    void nameChanged(QString arg);

public slots:
    void setName(QString arg);

private:
    QString m_name;

};

//QDebug operator<<(QDebug dbg, Person &p)
//{
//    dbg.nospace() << "(" << p.name() << ")";
//    return dbg.space();
//}

#endif // PERSON_H
