#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QEventLoop>

//#ifdef Q_OS_WIN
//#include <windows.h> //for sleep
//#endif
//void QTest::qSleep(int ms)
//{
//    QTEST_QSSERT(ms > 0);
//#ifdef Q_OS_WIN
//    Sleep(uint(ms));
//#else
//    struct timespec ts = {ms/ 1000, (ms % 1000) * 1000 * 1000};
//    nanosleep(&ts, NULL);
//#endif
//}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->btnExit->setText("Test");
    //Connect horizontalSlider and progressBar
    //connect(sender, signal, receiver);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));

    // to disconnect
//    delay(1000);
//    ui->lblShow->setText("Values changed");

//    disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
//            ui->progressBar,SLOT(setValue(int)));

}

void MainWindow::delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnExit_clicked()
{
    ui->lblShow->setText("Button is clicked");
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    delay(1000);
    ui->lblShow->setText("Values changed");
}
