#include "myjob.h"

void MyJob::stop()
{
    mStop = true;
}

MyJob::MyJob(QObject *parent) : QObject(parent)
{
    mStop = false;
}

void MyJob::start(QString name)
{
    mStop = false;
    for(int i = 0; i< 1000; i++)
    {
        if(mStop) return;
        qInfo() << "From Thread:" << i;
        emit onNumber(name, i);
        QThread::currentThread()->msleep(1000);
    }
}

MyJob::~MyJob()
{

}
