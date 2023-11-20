#include "mainwindow.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif

#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QProcess process;
//    QString path = "/home/vunguyen/dev/mimetik/glove-sdk/res/";
//    process.start("cp " + path+ "vu.json" + " " + path + "vu-copy.json");

    //process.close();

    /// Running the process with a list of arguments

    QObject *parent;
    QString program = "docker";
    QStringList arguments;
    arguments << "stop" << "2ab979507124";
    QProcess* process = new QProcess(parent);
    process->start(program, arguments);

    QProcess::ProcessState status = process->state();

    qInfo() << "Process status: " << status;

    w.show();
    return a.exec();
}
