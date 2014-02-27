#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

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


int main(int argc, char *argv[])
{

    Log4Qt::LogManager::rootLogger();
//    Log4Qt::TTCCLayout *p_layout = new Log4Qt::TTCCLayout();
    Log4Qt::SimpleTimeLayout *p_layout = new Log4Qt::SimpleTimeLayout();

    p_layout->setName(QLatin1String("My Layout"));
    p_layout->activateOptions();
    // Create an appender
//    Log4Qt::ConsoleAppender *p_appender = new Log4Qt::ConsoleAppender(p_layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
    Log4Qt::ColorConsoleAppender *p_appender = new Log4Qt::ColorConsoleAppender(p_layout, Log4Qt::ColorConsoleAppender::STDOUT_TARGET);

    p_appender->setName(QLatin1String("My Appender"));
    p_appender->activateOptions();
    // Set appender on root logger
    Log4Qt::Logger::rootLogger()->addAppender(p_appender);

    Log4Qt::Logger::logger(QLatin1String("My Logger"))->info("Hello World! %1 : %2", 23, "another inline string");

    // For this example, wizard-generates single line code would be good enough,
    // but very soon it won't be enough for you anyway, so use this more detailed example from start
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

//    Here's how you will add QML components whenever you start using them
//    Check https://github.com/amarchen/Wikipedia for a more full example
//    view->engine()->addImportPath(SailfishApp::pathTo("qml/components").toString());
    view->setSource(SailfishApp::pathTo("qml/main.qml"));

    view->show();

    return app->exec();
}
