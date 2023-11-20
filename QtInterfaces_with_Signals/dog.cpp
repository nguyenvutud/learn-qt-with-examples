#include "dog.h"

#include <QTimer>
#include <QRandomGenerator>

Dog::Dog(QObject *parent)
    : Animal(parent)
{
    //after 100ms call initateSound func
    QTimer::singleShot(100, this, &Dog::initateSound);
}

Dog::~Dog()
{

}

void Dog::initateSound(){
    emit makeSound("Woof!");
    //make a random sound between 100 and 1000
    int delay = QRandomGenerator::global()->bounded(100, 1000);
    QTimer::singleShot(delay, this, &Dog::initateSound);
}
