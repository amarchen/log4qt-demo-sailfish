#include <QtQuick>

#include "person.h"
#include "company.h"

#include <sailfishapp.h>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>

#include "ConsoleAppender"
#include "ColorConsoleAppender"
#include "SimpleTimeLayout"
#include "Logger"
#include "LogManager"

void initLogging()
{
    // Normally you call it all from .conf properties, but you can instantiate it manually too

    Log4Qt::LogManager::rootLogger();

    // Note that it doesn't work for QML logs from device
    Log4Qt::LogManager::setHandleQtMessages(true);


    Log4Qt::SimpleTimeLayout *p_layout = new Log4Qt::SimpleTimeLayout();

    p_layout->setName(QLatin1String("root layout"));
    p_layout->activateOptions();

    // Create an appender
    Log4Qt::ColorConsoleAppender *p_appender = new Log4Qt::ColorConsoleAppender(p_layout, Log4Qt::ColorConsoleAppender::STDOUT_TARGET);
    p_appender->setName(QLatin1String("root appender"));
    p_appender->activateOptions();

    // Set appender on root logger
    Log4Qt::Logger::rootLogger()->addAppender(p_appender);

    Log4Qt::Logger::logger(QLatin1String("Main Logger"))->info("Logging started");

    bool handingMessages = Log4Qt::LogManager::handleQtMessages();
    qDebug() << "Intercepting messages from qDebug is " << handingMessages;
}


int main(int argc, char *argv[])
{

    initLogging();
//    Person billGates("Bill Gates");
//    Person stevenElop("Steven Elop");
//    Company microsoft("Microsoft");
//    microsoft.setCeo(&billGates);
//    microsoft.setCeo(&stevenElop);

    qmlRegisterType<Person>("harbour.log4qtdemo", 0, 1, "Person");
    qmlRegisterType<Company>("harbour.log4qtdemo", 0, 1, "Company");
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo("qml/main.qml"));
//    view->rootContext()->setContextProperty("appVersion", APP_VERSION);
//    view->rootContext()->setContextProperty("appBuildNum", APP_BUILDNUM);
//    view->engine()->addImportPath(SailfishApp::pathTo("qml/components").toString());
//    view->engine()->addImportPath(SailfishApp::pathTo("lib").toString());

    view->show();

    return app->exec();
}
