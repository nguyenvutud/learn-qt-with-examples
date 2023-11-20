#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>

#include "test.h"

///https://www.youtube.com/watch?v=KugPAznC4Yo&list=PLUbFnGajtZlXbrbdlraCe3LMC_YH5abao&index=7
/// Note: QObject can not be copied
/// Because each object has its own address
/// and if we can copy, it will create many object with different addresses
/// but having the same signals and slots.
/// For example, switch and light.
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test test;

    //connect the signal and the slot
    //added Qt::QueuedConnection because we're in auto mode so we need q connection
    //we need to queue it in order to work properly
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    test.doStuff();

    int value = a.exec();

    qInfo() << "Exit value:" << value;
    return value;
}
