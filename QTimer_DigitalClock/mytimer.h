#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QTimer>

class MyTimer: public QObject
{
    Q_OBJECT
public:
    MyTimer(QObject * parent = nullptr);
    QTimer *timer;

    void start();
public slots:

    void stop();

    void myCounter();

private:
    int hour, minute, second;


signals:
    void updateValues(int hour, int min, int sec);
};

#endif // MYTIMER_H
