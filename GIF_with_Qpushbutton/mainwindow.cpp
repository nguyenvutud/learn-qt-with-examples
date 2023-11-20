#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMovie>

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


void MainWindow::on_btnLoadGifFile_clicked()
{
    //use QMovie to show a gif file
    QMovie *movie = new QMovie(":/icons/icons/animation_bye.gif");
    ui->label->setMovie(movie);
    movie->start();
}
