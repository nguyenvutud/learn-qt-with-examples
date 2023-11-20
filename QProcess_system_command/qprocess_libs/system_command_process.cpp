#include "system_command_process.h"
#include <QDebug>

void SystemCommandProcess::readStandardOutput()
{
    while(m_process->canReadLine())
    {
        qInfo() << m_process->readLine();
    }
}

void SystemCommandProcess::readStandardError()
{
    qInfo() << "Error:" << m_process->readAllStandardError();
}

SystemCommandProcess::SystemCommandProcess(QObject *parent) : QObject(parent)
{
    m_process = new QProcess();
}

SystemCommandProcess::~SystemCommandProcess()
{

}

void SystemCommandProcess::setProgram(QString prog)
{
    m_program = prog;
}

void SystemCommandProcess::setArguments(QStringList argList)
{
    m_arguments = argList;
}

void SystemCommandProcess::startProcess()
{

    QString arg="";
    for(QString a: m_arguments)
        arg = arg + a + " ";
    qInfo() << "Running: " << m_program << " " << arg;

    m_process->start(m_program, m_arguments);
}

void SystemCommandProcess::startAndWait()
{
    QString arg="";
    for(QString a: m_arguments)
        arg = arg + a + " ";
    qInfo() << "Running: " << m_program << " " << arg;

    m_process->start(m_program, m_arguments);

    //will wait forever until finished
    m_process->waitForFinished(-1);
}

void SystemCommandProcess::startAndReadOutputAsyn()
{
    QString arg="";
    for(QString a: m_arguments)
        arg = arg + a + " ";
    qInfo() << "Running: " << m_program << " " << arg;

    m_process->start(m_program, m_arguments);

    QObject::connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(readStandardOutput()));
    QObject::connect(m_process, SIGNAL(readyReadStandardError()), this, SLOT(readStandardError()));
}


QString SystemCommandProcess::getOutput()
{
    return m_process->readAllStandardOutput();
}

void SystemCommandProcess::startProcess(QString program, QStringList arguments)
{
    m_process->start(program, arguments);
}

void SystemCommandProcess::stopProcess()
{
    //process->waitForFinished();
    m_process->close();
}

QProcess::ProcessState SystemCommandProcess::statusProcess()
{
    return m_process->state();
}

long int SystemCommandProcess::checkContainerStatus()
{
    return m_process->pid();
}

void SystemCommandProcess::waitForFinished()
{
    m_process->waitForFinished();
}

void SystemCommandProcess::killProcess()
{
    m_process->kill();
}

void SystemCommandProcess::executeProcess(QString command, QStringList argList)
{
    QProcess::execute(command, argList);
}
