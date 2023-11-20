#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QDebug> //for qDebug() function

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
    //Type of messages
    //3 arguments
    //void about
    //void aboutQt
    //4 arguments
    //StandardButton critical
    //StandardButton information
    //StandardButton question
    //STandardButton warning

//    QMessageBox::about(this,"Title","This is my custom message");
//    QMessageBox::aboutQt(this,"Title");
//    QMessageBox::critical(this, "Title", "This is a custom message");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "This is a custom message",
                          QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "No is clicked";
    }
}
