#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    /*
     * don't need to declare an object in mainwindow.h
    SecondDialog secdial;
    //setModal: can't access to the main window when opening the second one
    secdial.setModal(true);
    secdial.exec();*/

    //need to declare an object in mainwindow.h, we can access to the main window when opening the second one
    hide();//hide the main window
    secDialog = new SecondDialog(this); //"this" is parent window
    secDialog->show();

}
