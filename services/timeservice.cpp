#include "timeservice.h"

#include <QTime>
#include <QTimer>

TimeService::TimeService(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&TimeService::handleTimerTick);
    //timer->callOnTimeout(this, &TimeWatcher::handleTimerTick);
    timer->setInterval(1000);
    timer->start();

}

void TimeService::throwError()
{
    throw "Break the Code!";
}

void TimeService::handleTimerTick()
{
    QTime time = QTime::currentTime();
    emit tickSeconds(time.toString("hh:mm:ss"));
}

