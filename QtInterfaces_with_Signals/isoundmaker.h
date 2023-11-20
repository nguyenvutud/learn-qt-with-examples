#ifndef ISOUNDMAKER_H
#define ISOUNDMAKER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class ISoundMaker
{
signals:
    virtual void makeSound(QString sound)=0;
};

//have to register this interface in the queue interface registry
Q_DECLARE_INTERFACE(ISoundMaker, "ISoundMaker");

#endif // ISOUNDMAKER_H
