#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>
//#include "Logger"  <-- would have been needed for LOG4QT_DECLARE_QCLASS_LOGGER

// Log4Qt has a handy macro LOG4QT_DECLARE_QCLASS_LOGGER that can declare logger right in the class definition
// It adds extra log4qt dependency to your header file however, so I like avoiding it as possible
// As you see, here, you don't have any log4qt dependency in the header and still have logger convenietnly
// defined in @see company.cpp

class Person;

class Company : public QObject
{
    Q_OBJECT
//    LOG4QT_DECLARE_QCLASS_LOGGER  <-- @see above
    Q_PROPERTY(Person* ceo READ ceo WRITE setCeo NOTIFY ceoChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Company(const QString& name = QString(), QObject *parent = 0);
    virtual ~Company();

    Person* ceo() const;
    QString name() const;

signals:
    void ceoChanged(Person* arg);
    void nameChanged(QString arg);

public slots:
    void setCeo(Person* arg);
    void setName(QString arg);

private:
    Person* m_ceo;
    QString m_name;
};

#endif // COMPANY_H
