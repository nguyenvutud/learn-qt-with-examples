#include "mainwindowchart.h"
#include "ui_mainwindowchart.h"

MainWindowChart::MainWindowChart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowChart)
{
    ui->setupUi(this);
}

MainWindowChart::~MainWindowChart()
{
    delete ui;
}

