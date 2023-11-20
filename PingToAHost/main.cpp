#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QProcess>
#include <QDebug>

#include "ping_services/PingServices.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PingServices ping;

    ping.OnPing();

//    int exitCode = QProcess::execute("ping", QStringList() << "192.168.178.31");
//    if (0 == exitCode) {
//        qInfo() << "it's alive";
//    } else {
//        qInfo() << "it's dead";
//    }

    qInfo() << "finished in main";

    return a.exec();
}
