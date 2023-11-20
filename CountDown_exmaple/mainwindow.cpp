#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "countdown_dialog.h"
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


void MainWindow::on_btnStart_clicked()
{
    CountDownDialog *countdownDial = new CountDownDialog(this);
    countdownDial->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    countdownDial->setAttribute(Qt::WA_NoSystemBackground);
    countdownDial->setAttribute(Qt::WA_TranslucentBackground);
    countdownDial->start(ui->txtSecond->toPlainText() == "" ? 5 : ui->txtSecond->toPlainText().toInt());
    countdownDial->show();
}
