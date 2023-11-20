#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
        QMessageBox::information(this,"Title", "Yes user likes apples");
    else {
        QMessageBox::information(this,"Title", "No user does not apples");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    //on_pushButton_clicked();
    //or
    if(arg1)
        QMessageBox::information(this,"Title", "Yes user likes apples");
    else {
        QMessageBox::information(this,"Title", "No user does not apples");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked())
        QMessageBox::information(this,"Title","Mark");
    if(ui->radioButton_2->isChecked())
        QMessageBox::information(this,"Title","John");

}
