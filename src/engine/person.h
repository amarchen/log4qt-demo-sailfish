#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDebug>

#if defined(LOG4QTDEMOENGINE_LIBRARY)
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_EXPORT
#else
#  define LOG4QTDEMOENGINE_EXPORT Q_DECL_IMPORT
#endif


class LOG4QTDEMOENGINE_EXPORT Person : public QObject
{
    Q_OBJECT
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
