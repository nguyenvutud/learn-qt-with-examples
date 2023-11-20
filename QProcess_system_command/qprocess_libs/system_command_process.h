#pragma once
#include <QtCore/qglobal.h>
#include <QProcess>
#include <QDebug>
#include <QtCore/QObject>

class SystemCommandProcess: public QObject
{
    //Allways add Q_OBJECT macro
    Q_OBJECT
    private:
        QProcess* m_process;
        QString m_program;
        QStringList m_arguments;

private slots:
        /**
         * @brief readStandardOutput reads the output line by line
         */
        void readStandardOutput();

        /**
         * @brief readStandardError read the standard error
         */
        void readStandardError();

    public:
        // use a null default parent
        explicit SystemCommandProcess(QObject *parent = nullptr);

        //SystemCommandProcess();

        ~SystemCommandProcess();
        /**
         * @brief setProgram
         * @param prog
         */
        void setProgram(QString prog);

        /**
         * @brief setArguments
         * @param argList
         */
        void setArguments(QStringList argList);

        /**
         * @brief startProcess
         */
        void startProcess();

        /**
         * @brief startAndWait to get the output
         */
        void startAndWait();

        /**
         * @brief startAndReadOutputAsyn uses to start a process
         * and asynchronously read the output data from output channel (stdout)
         */
        void startAndReadOutputAsyn();

        /**
         * @brief getOutput to get the output after running command
         * @return
         */
        QString getOutput();

        /**
         * @brief startProcess
         * @param command
         * @param argList
         */
        void startProcess(QString command, QStringList argList);

        /**
         * @brief stopProcess
         */
        void stopProcess();

        /**
         * @brief statusProcess
         * @return Status of process: QProcess::NotRunning/ Starting/ Running
         */
        QProcess::ProcessState statusProcess();

        long int checkContainerStatus();

        void waitForFinished();

        /**
         * @brief killProcess kills the current process, causing it to exit immediately
         */
        void killProcess();

        void executeProcess(QString command, QStringList argList);



};

