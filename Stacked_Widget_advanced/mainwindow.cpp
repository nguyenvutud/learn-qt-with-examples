#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &machineInfo);
    ui->stackedWidget->insertWidget(2, &machineSetting);
    connect(&machineInfo, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&machineSetting, SIGNAL(homeClicked()), this, SLOT(moveHome()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnMachineInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnMachineSetting_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
