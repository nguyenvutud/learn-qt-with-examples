#ifndef MYLISTNER_H
#define MYLISTNER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class MyListner : public QObject
{
    Q_OBJECT
public:
    explicit MyListner(QObject *parent = nullptr);

signals:

};

#endif // MYLISTNER_H
