#ifndef QMLLOGGER_H
#define QMLLOGGER_H

#include <QObject>

/**
 * @brief A Wrapper on top of Logger only for passing calls from Qml to Log4Qt's logger
 *        Doesn't cache logger simpler (as QML sets name property after creation)
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
