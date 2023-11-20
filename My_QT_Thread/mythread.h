#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore/qglobal.h>
#include <QThread>

/// https://www.youtube.com/watch?v=fM2THwKYqq8
///
/// use QMutex
/// https://www.youtube.com/watch?v=5WEiQ3VJfxc
class MyThread : public QThread
{
public:
    MyThread();
    QString name;
    void run();
    //for QMutex
    bool stop;
};

#endif // MYTHREAD_H
