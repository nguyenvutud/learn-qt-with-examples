#include <QObject>
#include "qtinterfaces.h"
#include "ui_qtinterfaces.h"
#include "dog.h"
#include "duck.h"

QtInterfaces::QtInterfaces(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtInterfaces)
{
    ui->setupUi(this);

    ISoundMaker* dog  = new Dog(this);
    ISoundMaker* duck = new Duck(this);

    QObject* dogAsObject = dynamic_cast<QObject*>(dog);
    QObject* duckAsObject = dynamic_cast<QObject*>(duck);

    //can't do this because dog is not a QObject
    //QObject::connect(dog, &Dog::makeSound, this, &QtInterfaces::onNewSound);
    QObject::connect(dogAsObject, SIGNAL(makeSound(QString)),
                     this, SLOT(onNewSound(QString)));


    QObject::connect(duckAsObject, SIGNAL(makeSound(QString)),
                     this, SLOT(onNewSound(QString)));

}

QtInterfaces::~QtInterfaces()
{
    delete ui;
}

void QtInterfaces::onNewSound(QString sound)
{
    ui->textEdit->setText(sound);
}

