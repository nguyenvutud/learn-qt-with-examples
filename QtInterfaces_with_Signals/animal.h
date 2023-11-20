#ifndef ANIMAL_H
#define ANIMAL_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QObject>
class Animal : public QObject
{
    Q_OBJECT

signals:

    ///&brief Emitted when the Animal jumps.
    void jumped();

public:
    Animal(QObject *parent);

    ~Animal();
public:
    /// @brief Starts running.
    void run();
};

#endif // ANIMAL_H
