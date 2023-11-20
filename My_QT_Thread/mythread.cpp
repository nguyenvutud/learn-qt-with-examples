#include "mythread.h"
#include <QDebug>
#include <QMutex>

MyThread::MyThread()
{

}
void MyThread::run()
{
    //ran
    qInfo() << this->name << " Running...";
    for(int i = 0; i < 100; i++)
    {
        /// other threads might access to "Stop" at the same time
        /// so to avoid this issue, we can use QMutex
        QMutex mutex;
        mutex.lock();
        //only this thread can modify this code
        if(this->stop)
        {
            break;
        }
        mutex.unlock();
        //then other thread coming/running
        this->msleep(10);
        qInfo() << this->name << i;
    }
}
