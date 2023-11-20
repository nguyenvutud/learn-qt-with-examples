#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include "mythread.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread myThread1;
    myThread1.name = "My thread 1";

    MyThread myThread2;
    myThread2.name = "My thread 2";

    MyThread myThread3;
    myThread3.name = "My thread 3";

    myThread1.start();
    myThread2.start();
    myThread3.start();

    std::cin.get();

    return a.exec();
}
