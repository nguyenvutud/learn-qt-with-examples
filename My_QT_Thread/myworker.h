#ifndef MYWORKER_H
#define MYWORKER_H

#include <QtCore/qglobal.h>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>

class MyWorker : public QThread
{
private:
    QMutex sync;
    QWaitCondition pauseCond;
    bool m_pause;
    bool m_stop;
public:
    MyWorker();
    void resume();
    void pause();
    void run();
    void stop();
};

#endif // MYWORKER_H
