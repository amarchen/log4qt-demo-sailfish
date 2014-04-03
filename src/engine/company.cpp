#include "company.h"
#include "person.h"

#include "Logger"

// LOG4QT_DECLARE_QCLASS_LOGGER in the header file looks a bit more clean, but adds extra log4qt header
// dependency from company.h This youself if you are fine with it
LOG4QT_DECLARE_STATIC_LOGGER(logger, Company)

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

/**
 * There are examples of printing some advanced info via Log4Qt
 * Note how you can print the exact location of a log message as both line number / file name
 * and as a function name. You probably cannot make a log4qt template for such messages,
 * but if you are into macros, you should be able to wrap it into some clever macro and have e.g.
 * LOG4QT_ERROR_WITH_LOCATION("problem happened") instead of logger->error("Problem happened: %1, Q_FUNC_INFO)
 *
 * TODO: Create such macros and propose them for merging into Log4Qt
 */
void Company::setCeo(Person* arg)
{
    if (m_ceo != arg) {
        logger()->warn() << "Setting CEO, think well. He is " << arg->name();
        if(arg->name().contains("elop", Qt::CaseInsensitive)) {
            // This prints something like the following:
            // 01.04.2014 01:15[0x6fb855a8] ERROR Company - Elop is about to become a CEO,
            // object pointer: 1874975280, at line number 41 of
            // file ../../../log4qt-demo/src/engine/company.cpp
            logger()->error("Elop is about to become a CEO, object pointer: %1, at line number %2 of file %3",
                            (int)arg, __LINE__, __FILE__);

            // This prints something like the following:
            // 01.04.2014 01:15[0x6fb855a8] FATAL Company - Elop to CEO? Aborting - void Company::setCeo(Person*)
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
