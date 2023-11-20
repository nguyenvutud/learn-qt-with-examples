#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::releaseSmoke);
    //1st param: an object will emit the signal, which object?
    //2nd param: name of signal
    //3th param: which object will receive the signal
    //4th param: function is owned by object in the 3th

    //connect two signals
    QObject::connect(this, &MainWindow::releaseSmoke, this, &MainWindow::onClicked);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::burnLogs);
    QObject::connect(this, &MainWindow::releaseSmoke, this, &MainWindow::villagersReact);

    //ex3
    //static so we don't need the 3th param
    QObject::connect(ui->pushButton, &QPushButton::clicked, &MainWindow::villagersReact_ex3);

    //ex4 with arguments

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::burnLogs_ex4);
    QObject::connect(this, &MainWindow::releaseSmoke_ex4, this, &MainWindow::villagersReact_ex4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClicked()
{
    ui->label->setText("Prepare for Invation!");
}

void MainWindow::burnLogs()
{
    emit releaseSmoke();
}


void MainWindow::villagersReact()
{
    ui->label->setText("Prepare for Invation!");
}

void MainWindow::villagersReact_ex3()
{

}

void MainWindow::burnLogs_ex4()
{
    emit releaseSmoke_ex4(15, 2);

}

void MainWindow::villagersReact_ex4(int param1)
{
    ui->label->setText(tr("Prepare for invation: %1").arg(param1));
}

