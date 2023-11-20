#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>
#include <QTimer>

#include "testsingleshot.h"

/// How to call QTimer::single shot from a static function
void staticFunction(){
    //call this func in 2s after executing the main function
    QTimer::singleShot(2000, [] ()->void{qInfo()<< "Static Func is called...";});
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestSingleShot *test = new TestSingleShot();

    test->startHello();

    staticFunction();

    return a.exec();
}
