#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->label,1);
    ui->statusbar->addPermanentWidget(ui->progressBar,3); //3: stretch
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage("Clicked", 5000);
    ui->label->setText("Clicked");
}
