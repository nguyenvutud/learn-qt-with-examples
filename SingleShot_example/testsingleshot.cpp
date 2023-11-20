#include <QDebug>
#include "testsingleshot.h"

TestSingleShot::TestSingleShot(QObject *parent) : QObject(parent)
{

}

void TestSingleShot::startHello()
{
    QTimer::singleShot(1000, this, SLOT(hello()));
}

void TestSingleShot::hello()
{
    qInfo() << "Hello !";
    QTimer::singleShot(1000, this, SLOT(hello()));
}
