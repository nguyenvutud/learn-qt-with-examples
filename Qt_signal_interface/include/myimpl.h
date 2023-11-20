#ifndef MYIMPL_H
#define MYIMPL_H

#include <QObject>
#include <QtCore/qglobal.h>
#include "my_interface1.h"
#include "my_interface2.h"

class MyImpl :
        virtual public MyInterface1,
        virtual public MyInterface2,
        public QObject
{
    Q_OBJECT
    Q_INTERFACES(MyInterface1)
    Q_INTERFACES(MyInterface2)

public:
    MyImpl(QObject *parent);
    ~MyImpl();

    void doWork();

signals:
    void event1() override;
    void event2() override;
};

#endif // MYIMPL_H
