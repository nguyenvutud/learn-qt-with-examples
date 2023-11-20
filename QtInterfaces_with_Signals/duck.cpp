#include "duck.h"
#include <QTimer>
#include <QRandomGenerator>

Duck::Duck(QObject *parent)
    : Animal(parent)
{
    QTimer::singleShot(100, this, &Duck::initateSound);

}

Duck::~Duck()
{

}

void Duck::initateSound()
{
    emit makeSound("Quak!");
    int delay = QRandomGenerator::global()->bounded(100, 1000);
    QTimer::singleShot(delay, this, &Duck::initateSound);
}
