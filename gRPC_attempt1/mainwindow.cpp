#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datacollection.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*gRPCClient = new GRPCClient()*/;
    rwJson.readJson();
    rwJson.writeJson();
    gRPCClient = new GRPCClient(grpc::CreateChannel(("localhost:50051"),
                                                       grpc::InsecureChannelCredentials()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSession()
{
//    GRPCClient gRPCClient(grpc::CreateChannel(("localhost:50051"),
//                                              grpc::InsecureChannelCredentials()));
    std::string reply = gRPCClient->CallInitSession();
    ui->txtResults->append(QString::fromStdString(reply));

}
void MainWindow::endSession()
{
    std::string reply = gRPCClient->CallEndSession();
    ui->txtResults->append(QString::fromStdString(reply));
}

void MainWindow::endProcess()
{
    std::string reply = gRPCClient->CallEndProcess();
    ui->txtResults->append(QString::fromStdString(reply));
}

void MainWindow::configProcessSession()
{
    std::string reply = gRPCClient->CallConfigProcess();
    ui->txtResults->append(QString::fromStdString(reply));
}
void MainWindow::getId()
{
    ui->txtResults->append(QString::number(gRPCClient->getReqId()));
}

void MainWindow::on_btnPerform_clicked()
{
    if(ui->rbtnInit->isChecked())
        initSession();
    else if (ui->rbtnEndRequest->isChecked()) {
        endProcess();
    }
    else if (ui->rbtnEndSession->isChecked())
    {
        endSession();
    }
    else if(ui->rbtnConfig->isChecked())
    {
        configProcessSession();
    }
    else if(ui->rbtnId->isChecked())
    {
        getId();
    }
}

void MainWindow::on_btnCollectData_clicked()
{
    dataCollection = new DataCollection(this);
    dataCollection->show();
}
