#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintertesting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/popup1.svg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    ui->testFrame->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    ui->label->setText("Width:" + QString::number(ui->testFrame->width()) + " Height:" + QString::number(ui->testFrame->height()));

    QPixmap bkgnd(":/images/popup1.svg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    ui->testFrame->setPalette(palette);
}


void MainWindow::on_pushButton_clicked()
{
    PainterTesting* test = new PainterTesting();
    test->show();
}
