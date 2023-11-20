#include "PingServices.hpp"

PingServices::PingServices(QObject *parent): QObject(parent)
{
    ip = "127.0.0.1";
}

PingServices::~PingServices()
{
    qInfo() << "In deconstructor of PingServices";
}

void PingServices::Stop()
{
    qInfo() << "Stopped";
}

bool PingServices::simplePing(QString ip)
{
    int exitCode = QProcess::execute("ping", QStringList() << ip);
    if (0 == exitCode) {
        return true;
    } else {
        return false;
    }
}

void PingServices::OnPing()
{
    QObject::connect(&mPingProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(OnPingEnded(int, QProcess::ExitStatus)));

    #ifdef __linux__
       mPingProcess.start("ping", QStringList() << "-c" << "2" << ip);
    #else
       mPingProcess.start("ping", QStringList() << "-n" << "2" << ip);
    #endif
}

void PingServices::OnPingEnded(int exitCode, QProcess::ExitStatus exitSt)
{
    qInfo() << "Params: exitCode:" << exitCode << " exitStatus:" << exitSt;

    QByteArray output = mPingProcess.readAllStandardOutput();
    if (!output.isEmpty())
    {
        qDebug() << output;
        if (-1 != QString(output).indexOf("ttl", 0, Qt::CaseInsensitive))
        {
           qDebug() << "PING OK";
        }
        else
        {
           qDebug() << "PING KO";
        }
    }
    qDebug() << "Ping finished.";

    QObject::disconnect(&mPingProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(OnPingEnded(int, QProcess::ExitStatus)));

    return;
}


