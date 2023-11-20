#ifndef DUCK_H
#define DUCK_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include "isoundmaker.h"
#include "animal.h"

class Duck : public Animal, virtual public ISoundMaker
{
    Q_OBJECT

    Q_INTERFACES(ISoundMaker);

public:
    Duck(QObject *parent);
    ~Duck();

public slots:
    void initateSound();

signals:
    /// @brief Implement the IsoundMaker interface
    void makeSound(QString sound) override;
};

#endif // DUCK_H
