#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolTip::showText(ui->pushButton->mapFromGlobal(QPoint(0, 0)), "Click here to execute the program");
    ui->pushButton->setToolTip("Click <font color='red'><b>here</b></font> to execute the program"
                               "<ul>"
                               "<li>Item 1</li>"
                               "<li>Item 2</li>"
                               "<li>Item 3</li>"
                               "</ul>");
    ui->pushButton_2->setToolTip("<img src=':/icons/checked.png'> Hello world");

    ui->pushButton_3->setStyleSheet("QToolTip { color: #ffffff; background-color: #000000; border: 1px; border-color: red; border-radius: 5px; }");
    ui->pushButton_3->setToolTip("Here is tooltip text");

    ui->pushButton_4->setToolTip("<span style=\"background-color:red;\">test</span>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

