#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap("qrc:/images/shark-background.png");
    int w = ui->centralFrame->width();
    int h = ui->centralFrame->height();
    pixmap.scaled(w, h, Qt::KeepAspectRatio);
    palette.setBrush(QPalette::Background, pixmap);

    ui->centralFrame->setPalette(palette);


}

MainWindow::~MainWindow()
{
    delete ui;
}

