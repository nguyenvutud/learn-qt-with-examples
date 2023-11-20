#include "dialog.h"
#include "ui_dialog.h"
#include "myjob.h"
#include <QDebug>
#include <QThread>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //QFuture<void> test = QtConcurrent::run();

    connect(&myJob, &MyJob::onNumber, this, &Dialog::onNumberChanged);
    connect(this, &Dialog::onStop, &myJob, &MyJob::stop);
}

Dialog::~Dialog()
{
    emit onStop();
    delete ui;

}


void Dialog::on_btnStart_clicked()
{

//    connect(&myJob, &MyJob::onNumber, this, &Dialog::onNumberChanged);
//    connect(this, &Dialog::onStop, &myJob, &MyJob::stop);
    QFuture<void> test = QtConcurrent::run(&this->myJob, &MyJob::start, QString("Kitten"));
}

void Dialog::on_btnStop_clicked()
{
    emit onStop();

//    disconnect(&myJob, &MyJob::onNumber, this, &Dialog::onNumberChanged);
//    disconnect(this, &Dialog::onStop, &myJob, &MyJob::stop);

}

void Dialog::onNumberChanged(QString name, int number)
{
    qInfo() << "From Dialog: " << name << " " << QString::number(number);
    ui->lineEdit->setText(name + QString::number(number));
}
