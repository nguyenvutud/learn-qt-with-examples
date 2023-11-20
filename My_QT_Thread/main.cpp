#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>

#include "mythread.h"
#include "myworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mythread1;
    mythread1.name = "My thread 1";
    mythread1.stop = false;

    MyThread mythread2;
    mythread2.name = "My thread 2";
    MyThread mythread3;
    mythread3.name = "My thread 3";

    mythread1.start(QThread::HighestPriority);
//    mythread2.start();
//    mythread3.start(QThread::LowestPriority);


    for(int i = 0; i<100; i++)
    {
        qInfo() << "1. Main thread: " << i;
        QThread::msleep(5);
    }
    mythread1.stop = true;

    for(int i = 0; i<10; i++)
    {
        qInfo() << "2. Main thread: " << i;
        QThread::msleep(5);
    }
    //if we call start() the thread will start at the beginning
    mythread1.stop = false;
    mythread1.start();

    ///How to stop and resume thread
    /// https://stackoverflow.com/questions/9075837/pause-and-resume-a-qthread
    ///

    MyWorker stopandresumeThread;
    stopandresumeThread.start();
    qInfo() << "Sleeping 1s before performing pause() thread";
    QThread::sleep(1);
    stopandresumeThread.pause();

    qInfo() << "Main: Sleeping 1s before performing resume() thread";
    QThread::sleep(1);
    stopandresumeThread.resume();
    qInfo() << "Main: Sleeping 1s before performing stop() thread";
    QThread::sleep(1);
    stopandresumeThread.stop();

    qInfo() << "Main: Stopped thread";
    mythread1.deleteLater();

    return a.exec();
}
