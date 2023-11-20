#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include <grpcpp/grpcpp.h>

#include "MPUInterface.pb.h"
#include "MPUInterface.grpc.pb.h"
#include "gRPCClient.h"
#include "Session.h"
#include "json/read_write_json.h"
#include "datacollection.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using Interface::InitSessionReq;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void initSession();
    void endSession();
    void configProcessSession();
    void endProcess();
    void getId();

    void on_btnPerform_clicked();


    void on_btnCollectData_clicked();

private:
    Ui::MainWindow *ui;
    GRPCClient *gRPCClient;
    ReadWriteJson rwJson;
    DataCollection *dataCollection;
};
#endif // MAINWINDOW_H
