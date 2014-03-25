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
//#include "SystemlogAppender"
//#include "Level"
//#include "DailyRollingFileAppender"
//#include "helpers/factory.h"
//#include "Appender"


#include "PropertyConfigurator"

#include <QFile>
#include "qmllogger.h"

//Log4Qt::Appender *create_system_log_appender() {
//    return new Log4Qt::SystemLogAppender;
//}

/**
 * @brief initLogging
 * @param app Is used for determining app-specific config, log file locations, etc
 */
void initLogging(const QCoreApplication& app)
{

    const QString& binaryName = QCoreApplication::applicationName();
    const QString logConfigFilePath("/home/nemo/.config/" + binaryName + "/log4qt.conf");
    const QString fallbackLogConfigPath("/usr/share/" + binaryName + "/log4qt.conf");

    const QString& usedConfigFile = QFile::exists(logConfigFilePath) ? logConfigFilePath : fallbackLogConfigPath;
    Log4Qt::PropertyConfigurator::configure(usedConfigFile);
    Log4Qt::LogManager::setHandleQtMessages(true);

    qDebug() << "Using following log config file: " << usedConfigFile;


    /**
    // Normally you call it all from .conf properties, but you can instantiate it manually too
    Log4Qt::Factory::registerAppender("org.apache.log4j.SystemLogAppender", create_system_log_appender);
    Log4Qt::LogManager::rootLogger();

    // Note that it doesn't work for QML logs from device

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


    bool handingMessages = Log4Qt::LogManager::handleQtMessages();
    qDebug() << "Intercepting messages from qDebug is " << handingMessages;
    qDebug() << "temp loc" << QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    qDebug() << "config loc" << QStandardPaths::standardLocations(QStandardPaths::ConfigLocation);
    qDebug() << "cache loc" << QStandardPaths::standardLocations(QStandardPaths::CacheLocation);
    qDebug() << "generic cache loc" << QStandardPaths::standardLocations(QStandardPaths::GenericCacheLocation);
    qDebug() << "data loc" << QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    qDebug() << "generic data loc" << QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    qDebug() << "appName: " << QCoreApplication::applicationName();
    qDebug() << "appFilePath: " << QCoreApplication::applicationFilePath();
    qDebug() << "appDirPath: " << QCoreApplication::applicationDirPath();
}


int main(int argc, char *argv[])
{

    qmlRegisterType<Person>("harbour.log4qtdemo", 0, 1, "Person");
    qmlRegisterType<Company>("harbour.log4qtdemo", 0, 1, "Company");
    qmlRegisterType<QmlLogger>("harbour.log4qtdemo", 0, 1, "Logger");
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    initLogging(*app);

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    qDebug() << "app's name: " << app->applicationName();
    qDebug() << "app's die path: " << app->applicationDirPath();

    view->setSource(SailfishApp::pathTo("qml/main.qml"));
//    view->rootContext()->setContextProperty("appVersion", APP_VERSION);
//    view->rootContext()->setContextProperty("appBuildNum", APP_BUILDNUM);
//    view->engine()->addImportPath(SailfishApp::pathTo("qml/components").toString());
//    view->engine()->addImportPath(SailfishApp::pathTo("lib").toString());

    view->show();

    return app->exec();
}
