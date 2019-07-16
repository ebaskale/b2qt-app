#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include <QObject>
#include <QTimer>

class TimeService : public QObject
{
    Q_OBJECT
public:
    explicit TimeService(QObject *parent = nullptr);
signals:
    void tick(const QString time);
public slots:

private:
    QTimer *timer;
    void handleTimerTick();
};

#endif // TIMESERVICE_H
