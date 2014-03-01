#include "company.h"
#include "person.h"

Company::Company(const QString &name, QObject *parent) :
    QObject(parent), m_ceo(NULL)
{
    setName(name);
}

Company::~Company()
{
    logger()->info() << "Company destroyed";
}

Person* Company::ceo() const
{
    return m_ceo;
}

QString Company::name() const
{
    return m_name;
}

void Company::setCeo(Person* arg)
{
    if (m_ceo != arg) {
        logger()->warn() << "Setting CEO, think well. He is " << arg->name();
        if(arg->name().contains("elop", Qt::CaseInsensitive)) {
            logger()->error("Elop is about to become a CEO, object pointer: %1", (int)arg);
            logger()->fatal("Elop to CEO? Aborting - %1", Q_FUNC_INFO);
        }
        m_ceo = arg;
        emit ceoChanged(arg);
    }
}

void Company::setName(QString arg)
{
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}
