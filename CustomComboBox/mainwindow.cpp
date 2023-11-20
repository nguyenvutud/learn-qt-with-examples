#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cmbTest->addItem("AAAAAAAA");
    ui->cmbTest->addItem("BBBBBBBB");

    //this is a simple workaround
    auto space = QString(" ");
    placeholder = new QLabel(space + "Select something...");
    ui->cmbTest->setLayout(new QVBoxLayout());
    ui->cmbTest->layout()->setContentsMargins(0, 0, 0, 0);
    ui->cmbTest->layout()->addWidget(placeholder);
    //QObject::connect(this, &QComboBox::currentIndexChanged, &ui->cmbTest, [placeholder](int index){placeholder->setVisible(index == -1); });

    ui->cmbTest->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmbTest_currentIndexChanged(int index)
{
    if(placeholder != nullptr)
    {
        if(index == -1)
            placeholder->setVisible(true);
        else
            placeholder->setVisible(false);
    }

    //ui->cmbTest->setCurrentIndex(index);

}

void MainWindow::on_cmbTest_currentTextChanged(const QString &arg1)
{
    if(ui->cmbTest->currentText() == "")
    {
        if(placeholder)
        {
            placeholder->setVisible(true);
        }
    }
}
