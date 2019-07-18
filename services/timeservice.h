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
    void tickSeconds(const QString time);

public slots:
   void throwError();

private:
    QTimer *timer;
    void handleTimerTick();
};

#endif // TIMESERVICE_H
