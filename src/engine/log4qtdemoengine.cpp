#include "log4qtdemoengine.h"

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
