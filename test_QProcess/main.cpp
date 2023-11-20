#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QProcess>
#include "/home/vunguyen/dev/mimetik/glove-sdk/system_cmd_libs/system_command_process.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SystemCommandProcess *process = new SystemCommandProcess();

    process->setProgram("./home/vunguyen/dev/mimetik/sense/bin/sense");

    process->startAndReadOutputAsyn();

    return a.exec();
}
