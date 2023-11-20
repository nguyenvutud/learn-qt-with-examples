#ifndef DOG_H
#define DOG_H

#include <QtCore/qglobal.h>
#include "animal.h"
#include "isoundmaker.h"

class Dog : public Animal, virtual public ISoundMaker
{
    Q_OBJECT
    //define Q interface
    Q_INTERFACES(ISoundMaker);

public:
    Dog(QObject *parent);
    ~Dog();
public slots:
    void initateSound();

signals:
    /// @brief Implement the IsoundMaker interface
    void makeSound(QString sound) override;
};

#endif // DOG_H
