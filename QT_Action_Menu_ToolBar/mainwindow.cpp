#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/rec/icons/new.png"), "1");
    ui->comboBox->addItem(QIcon(":/rec/icons/open.png"), "2");
    ui->comboBox->addItem(QIcon(":/rec/icons/exit.png"), "3");

    //for listWidget
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/icons/new.png"),"1");
    ui->listWidget->addItem(item);
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/rec/icons/open.png"),"2");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/rec/icons/exit.png"),"3");
    ui->listWidget->addItem(item2);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Title",QString::number(ui->comboBox->currentIndex()));
}

void MainWindow::on_pushButton_2_clicked()
{
    //QMessageBox::information(this,"Title",ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}
