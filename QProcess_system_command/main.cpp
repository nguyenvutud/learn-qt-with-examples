#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <qprocess_libs/system_command_process.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Starting program";

    SystemCommandProcess *sysCmd = new SystemCommandProcess(nullptr);
    sysCmd->setProgram("sh");
    QString args = "run.sh";
    sysCmd->setArguments(args.split(" "));

    qInfo() << "Starting commands";

    sysCmd->startAndWait();

    //could not perform this from static main
    //sysCmd->startAndReadOutputAsyn();

    QString output = sysCmd->getOutput();

    qInfo() << "Output:" << output;

    if(output.contains("Up "))
        qInfo() << "Server is Up";

    else if (output.contains("Exited "))
            qInfo() << "Server is Stop but the name is still in the list";

    qInfo() << "Ctrl+c to end the program";

    return a.exec();
}
