#include <QVBoxLayout>
#include <QFrame>
#include <QSlider>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(200, 200);
    circularProgressbar = new CircularProgressBar();
    //Create Container and layout


    //add slider
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    //Add widgets
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(circularProgressbar, Qt::AlignCenter, Qt::AlignCenter);

    layout->addWidget(slider, Qt::AlignCenter, Qt::AlignCenter);

    ui->frame->setStyleSheet("background-color: transparent");
    ui->frame->setLayout(layout);

    circularProgressbar->setValue(70);
    circularProgressbar->setInnerImageSize(100, 100);

    circularProgressbar->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

