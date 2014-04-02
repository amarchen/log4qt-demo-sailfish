#include <QtQuick>

#include "person.h"
#include "company.h"

#include <sailfishapp.h>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>

#include "Logger"
#include "LogManager"

// Includes below are needed for manual configuration. If you use .conf file for configuring,
// just PropertyConfigurator is enough
//#include "ConsoleAppender"
//#include "ColorConsoleAppender"
//#include "SimpleTimeLayout"
//#include "Level"
//#include "DailyRollingFileAppender"

#include "SystemlogAppender"
#include "FileAppender"
#include "helpers/factory.h"
#include "Appender"


#include "PropertyConfigurator"

#include <QFile>
#include "qmllogger.h"

// For some reason exactly SystemLogAppender doesn't have a factory registered in log4qt,
// so in order for it to be instantiatable from .conf file (or even in general?) we declare factory
// right here and will register it in initLoggin()
Log4Qt::Appender *create_system_log_appender() {
    return new Log4Qt::SystemLogAppender;
}


/**
 * @brief initLogging
 * A lot of commented code in this method is the alternative way of setting up same (or similar)
 * logger's structure as .conf file orders
 * TODO: extract this manual creation and .conf-based creation into the separate method and just
 *       comment out the call for the manual one
 */
void initLogging()
{
    // Should really be done in log4qt, but somehow it's missing these
    Log4Qt::Factory::registerAppender("org.apache.log4j.SystemLogAppender", create_system_log_appender);

    // Sailfish OS-specific locations for the app settings files and app's own files
    // First we check if log4qt.conf is present in .config If it isn't present we fallback to the .conf file
    // in the app's data folder
    //
    // This way normally your app can produce minimal logging based on data folder file settings
    // And when user has troubles and more logging is needed, you can just drop and extra conf file to .config
    // (e.g. via increasedLoggingPackage RPM installation)
    const QString& binaryName = QCoreApplication::applicationName();
    const QString logConfigFilePath("/home/nemo/.config/" + binaryName + "/log4qt.conf");
    const QString fallbackLogConfigPath("/usr/share/" + binaryName + "/log4qt.conf");

    const QString& usedConfigFile = QFile::exists(logConfigFilePath) ? logConfigFilePath : fallbackLogConfigPath;
    Log4Qt::PropertyConfigurator::configure(usedConfigFile);

    // Uglyish hack for replacing $XDG_CACHE_HOME with the proper cache directory
    // TODO: Implement replacing of $XDG_CACHE_HOME (and other vars?) with the proper values before configuring log4qt

    // Iterate all appenders attached to root logger and whenever a FileAppender (or its descender found), replace
    // $XDG_CACHE_HOME with the proper folder name
    QList<Log4Qt::Appender *> appenders = Log4Qt::LogManager::rootLogger()->appenders();
    QList<Log4Qt::Appender *>::iterator i;
    for (i = appenders.begin(); i != appenders.end(); ++i) {
          Log4Qt::FileAppender* fa = qobject_cast<Log4Qt::FileAppender*>(*i);
          if(fa) {
              QString filename = fa->file();
              filename.replace("$XDG_CACHE_HOME",
                              QStandardPaths::standardLocations(QStandardPaths::CacheLocation).at(0)
                              );
              fa->setFile(filename);
              fa->activateOptions();
          }
    }

    // For capturing qDebug() and console.log() messages
    // Note that console.log() might fail in Sailfish OS device builds. Not sure why, but it seems like
    // console.log() exactly in Sailfish OS device release builds doesn't go through the same qDebug() channel
    Log4Qt::LogManager::setHandleQtMessages(true);

    qDebug() << "Using following log config file: " << usedConfigFile;


    /**
    // Normally you call it all from .conf properties, but you can instantiate it manually too
    Log4Qt::LogManager::rootLogger();

    Log4Qt::SimpleTimeLayout *p_layout = new Log4Qt::SimpleTimeLayout();

    p_layout->setName(QLatin1String("root layout"));
    p_layout->activateOptions();

    // Create an appender
    Log4Qt::ColorConsoleAppender *p_consoleAppender = new Log4Qt::ColorConsoleAppender(p_layout, Log4Qt::ColorConsoleAppender::STDOUT_TARGET);
    p_consoleAppender->setName(QLatin1String("root console appender"));
    p_consoleAppender->activateOptions();

    Log4Qt::SystemLogAppender *p_syslogAppender = new Log4Qt::SystemLogAppender();
    p_syslogAppender->setServiceName("journalctl");
    p_syslogAppender->setName(QLatin1String("root sysylog appender"));
    p_syslogAppender->setLayout(p_layout);

    // Root logger gets all levels of logs, but let's send only
    // important ones to syslog
    p_syslogAppender->setThreshold(Log4Qt::Level(Log4Qt::Level::ERROR_INT));

    p_syslogAppender->activateOptions();

    Log4Qt::DailyRollingFileAppender *p_fileAppender =
            new Log4Qt::DailyRollingFileAppender();
    p_fileAppender->setFile(QStandardPaths::writableLocation(QStandardPaths::CacheLocation)
                            + "/" + applicationName + "/" + applicationName +".log");
    p_fileAppender->setDatePattern(Log4Qt::DailyRollingFileAppender::DAILY_ROLLOVER);
    p_fileAppender->setLayout(p_layout);
    p_syslogAppender->setName(QLatin1String("root file appender"));
    p_fileAppender->activateOptions();


    // Set appenders on root logger
    Log4Qt::Logger::rootLogger()->addAppender(p_consoleAppender);
    Log4Qt::Logger::rootLogger()->addAppender(p_syslogAppender);
    Log4Qt::Logger::rootLogger()->addAppender(p_fileAppender);
    */

    Log4Qt::Logger::logger(QLatin1String("Main Logger"))->info("Logging started");
}


int main(int argc, char *argv[])
{
    qmlRegisterType<QmlLogger>("harbour.log4qtdemo", 0, 1, "Logger");
    qmlRegisterType<Person>("harbour.log4qtdemo", 0, 1, "Person");
    qmlRegisterType<Company>("harbour.log4qtdemo", 0, 1, "Company");

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));

    // Init logging should be called after app object creation as initLogging() will examine
    // QCoreApplication for determining the .conf files locations
    initLogging();

    // A short demo of printing an object to qDebug() and LogStream from c++
    // TODO: Move to some other place. At least to a stand-alone function
    Person ivan("Ivan Kuztetsov");
    Log4Qt::Logger::rootLogger()->debug("trying streaming object now");
    Log4Qt::Logger::rootLogger()->info() << ivan;
    Log4Qt::Logger::rootLogger()->info() << "Ivan via LogStream: " << ivan;
    qDebug() << "Ivan via QDebug stream: " << ivan;


    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->setSource(SailfishApp::pathTo("qml/main.qml"));
    view->show();

    return app->exec();
}
