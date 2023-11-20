#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QTextStream> //for text stream IO
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction())); //

    timer->start(1000); //take time in ms
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a file",QDir::currentPath());

    if(!QFile::exists(filename))
        filename = "/home/vunguyen/QT_workspace/QT_QDir_QFile/myfile.txt";

    QFile file(filename);
    //check file is open or not
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Open File", "File is not open");
    }
    QTextStream out(&file);

    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
    QMessageBox::information(this,"Write File", "Done!");

}

void MainWindow::on_pushButton_clicked()
{
    QString filter = "All Files (*.*) ;; Text Files (*.txt) ;; XML Files (*.xml)";
    QString filename = QFileDialog::getOpenFileName(this,"Open a file",QDir::currentPath(), filter);

    if(!QFile::exists(filename))
        filename = "/home/vunguyen/QT_workspace/QT_QDir_QFile/myfile.txt";

    QFile file(filename);
    //QFile file("/home/vunguyen/QT_workspace/QT_QDir_QFile/myfile.txt");
    //check file is open or not
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Open File", "File is not open");
    }
    QTextStream in(&file);

    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    QMessageBox::information(this,"Read File", "Done!");

}

void MainWindow::myfunction()
{
    //qDebug() << "update...";
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->lblTime->setText(time_text);

}
