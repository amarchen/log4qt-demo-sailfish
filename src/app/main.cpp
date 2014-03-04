#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include "person.h"
#include "company.h"

#include "log4qtdemoengine.h"

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
}


int main(int argc, char *argv[])
{

    initLogging();
    Person billGates("Bill Gates");
    Person stevenElop("Steven Elop");
    Company microsoft("Microsoft");
    microsoft.setCeo(&billGates);
    microsoft.setCeo(&stevenElop);

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo("qml/main.qml"));

    view->show();

    return app->exec();
}
