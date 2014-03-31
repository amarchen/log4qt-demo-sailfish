#ifndef QMLLOGGER_H
#define QMLLOGGER_H

#include <QObject>

/**
 * @brief A Wrapper on top of Logger only for passing calls from Qml to Log4Qt's logger
 *        Something like this should be a part of log4qt actually. Or the basic logger there
 *        could have its methods declared as Q_INVOKABLE for making it possible to call methods from QML
 */
class QmlLogger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit QmlLogger(QObject *parent = 0);

    // Port overloads with many arguments as well if you like
    // Just string could be good enough as in JavaScript logs
    // concatenation is natural anyway
    Q_INVOKABLE void trace(const QString &rMessage) const;
    Q_INVOKABLE void debug(const QString &rMessage) const;
    Q_INVOKABLE void info(const QString &rMessage) const;
    Q_INVOKABLE void error(const QString &rMessage) const;
    Q_INVOKABLE void fatal(const QString &rMessage) const;

    QString name() const;

signals:

    void nameChanged(QString arg);

public slots:

void setName(QString arg);

private:
    QString m_name;

};

#endif // QMLLOGGER_H
