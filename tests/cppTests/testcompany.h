#ifndef TESTCOMPANY_H
#define TESTCOMPANY_H

#include <QObject>

class TestCompany : public QObject
{
    Q_OBJECT
public:
    explicit TestCompany(QObject *parent = 0);

private slots:
    void emitsNameChangedSignal();

};

#endif // TESTCOMPANY_H
