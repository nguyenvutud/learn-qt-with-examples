#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);

    blackPen.setWidth(6);
    ellipse = scene->addEllipse(10, 10, 100, 100, blackPen, redBrush);
    rect = scene->addRect(20, 20, 100, 100, blackPen, blueBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->rotate(-10);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(10);
}
