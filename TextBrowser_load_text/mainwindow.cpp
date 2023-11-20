#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("text.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "Error", file.errorString());
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());

}
