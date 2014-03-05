#ifndef TESTPERSON_H
#define TESTPERSON_H

#include <QObject>

class TestPerson : public QObject
{
    Q_OBJECT
public:
    explicit TestPerson(QObject *parent = 0);

signals:

public slots:

private slots:
    void emitsNameChangedSignal();

};

#endif // TESTPERSON_H
