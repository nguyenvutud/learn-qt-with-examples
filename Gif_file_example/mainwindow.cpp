#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMovie *movie = new QMovie(":/img/images/confetti.gif");

    ///show the gif file with all current components
//    ui->frameSub->setVisible(false);
    QLabel *lblGifShowing = new QLabel(this);
//    ui->layout->addWidget(lblGifShowing);


    ///show the gif file with a new Widget
    /// and show it in entire main widget
    /// but we could not click to the existed ones.

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(lblGifShowing);

    lblGifShowing->setGeometry(this->geometry());
    lblGifShowing->setMovie(movie);
//    lblGifShowing->setEnabled(false);

    movie->start();
    //set a widget on the top of all
    ui->pushButton->setParent(lblGifShowing);
    ui->pushButton->raise();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Test", "Testing");
}
