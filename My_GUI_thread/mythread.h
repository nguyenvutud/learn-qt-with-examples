#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore/qglobal.h>
#include <QThread>

///
/// \brief The MyThread class
///https://www.youtube.com/watch?v=PR6wVy7Et1A
///
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void run();
    //void stop();
    bool stop;
signals:
    void NumberChanged(int);

};

#endif // MYTHREAD_H
