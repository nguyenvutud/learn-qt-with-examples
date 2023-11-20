#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 1; i <= 10; i++)
    {
        ui->comboBox->addItem("PersonID " + QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

