#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QObject>
#include <QtNetwork>

class networktest : public QObject
{
    Q_OBJECT
public:
    explicit networktest(QObject *parent = nullptr);

signals:

public slots:
    QString getNames();
};

#endif // NETWORKTEST_H
