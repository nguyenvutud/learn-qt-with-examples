#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>
#include "mytimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this) ;
    connect(timer, SIGNAL(timeout()), this, SLOT(myFunction()));
    timer->start(1000);

    connect(&myTimer, SIGNAL(updateValues(int,int,int)), this, SLOT(onNewValues(int,int,int)));
    connect(this, SIGNAL(stopCounter()), &myTimer, SLOT(stop()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myFunction()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    if(time.second() % 2 == 0)
    {
        timeText[3] = ' ';
        timeText[8] = ' ';
    }
    ui->lblDateTime->setText(timeText);
}

void MainWindow::onNewValues(int hours, int mins, int secs)
{
    QString text = "";
    text = QString::number(mins) + ":" + QString::number(secs);
    if(hours > 0)
        text = QString::number(hours) + ":" + text;
    QTime time;
    time.setHMS(hours, mins, secs);

    ui->lblCounter->setText(time.toString("hh:mm:ss"));

}


void MainWindow::on_btnStart_clicked()
{
    myTimer.start();
}

void MainWindow::on_btnStop_clicked()
{
    emit stopCounter();
}
