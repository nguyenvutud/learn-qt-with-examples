#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    myThread = new MyThread(this);

    connect(myThread, SIGNAL(NumberChanged(int)), this, SLOT(onNumberChanged(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberChanged(int number)
{
    ui->label->setText(QString::number(number));
}


void Dialog::on_btnStart_clicked()
{
    myThread->stop = false;
    myThread->start();
}

void Dialog::on_btnStop_clicked()
{
    myThread->stop = true;
}
