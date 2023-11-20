#include <QDebug>
#include "mytimer.h"

MyTimer::MyTimer(QObject *parent): QObject(parent)
{
    hour = 0;
    minute = 0;
    second = 0;
}

void MyTimer::start()
{
    hour = 0;
    minute = 0;
    second = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myCounter()));
    timer->start(1000);
}

void MyTimer::stop()
{
    hour = 0;
    minute = 0;
    second = 0;
    timer->stop();
}

void MyTimer::myCounter()
{
    second += 1;
    if (second == 60)
    {
        minute += 1;
        second = 0;
    }
    if(minute >= 60)
    {
        hour += 1;
        minute = 0;
    }

    emit updateValues(hour, minute, second);
    qDebug() << "Timer executed";
}
