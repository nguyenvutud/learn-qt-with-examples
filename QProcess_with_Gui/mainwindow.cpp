#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testCommand();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testCommand()
{
    m_process = new SystemCommandProcess(nullptr);
    //SystemCommandProcess *m_test = new SystemCommandProcess();
    m_process->setProgram("sh");
    QString args = "run.sh";
    m_process->setArguments(args.split(" "));

    qInfo() << "Starting commands";

//    m_test->startAndWait();
    //could not perform this from static main
    m_process->startAndReadOutputAsyn();
}


void MainWindow::on_btnKillProcess_clicked()
{
    m_process->killProcess();
    qInfo() << "Process has been killed...";
}
