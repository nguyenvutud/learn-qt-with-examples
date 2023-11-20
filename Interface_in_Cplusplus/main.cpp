#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>
#include <iostream>
#include <QTime>
#include <QThread>

/// from this video https://www.youtube.com/watch?v=UWAdd13EfM8
/// will introduce what is the interface (or a pure virtual functions)
/// In c++, an interface is a class (we don't have a keyword 'interface' like other languagues
///
/// A pure virtual function in c++ is essentially the same as an abstract method
/// or an interface in other languagues such as Java or C#.
/// Basically a pure virtual function allows us to define in a base class
/// that does not have an implementation and then for subclasses to
/// actually implement that function
class Printable
{
public:
    virtual QString getClassName() = 0; //the equals zero is essentially making it a pure virtual function
                                            // meaning that it has to be implemented in a sub-class if you want to be able to instantiate that class
};

class Entity : public Printable
{
public:
    virtual QString getName() {return "Entity"; }
    QString getClassName() override {return "Entity";}
};

class Player: public Entity
{
private:
    QString m_Name;
public:
    Player(const QString & name)
        :m_Name(name){}

    QString getName() override {return m_Name; }
    QString getClassName() override {return "Player"; }
};

///We can create many classes here, but it should have an implementation of
/// function getClassName(), otherwise, it will not work properly
class A: public Printable
{
public:
    QString getClassName() override {return "A"; }
};

void printName(Entity* entity)
{
    qInfo() << entity->getName();
}

void Print(Printable* obj)
{
    qInfo() << obj->getClassName();
}

void delay(int milliseconds)
{
    QTime delay = QTime::currentTime().addMSecs(milliseconds);
    while(QTime::currentTime() < delay)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Testing...";

    //Entity* e = new Entity();
    //printName(e);

    //Player* p = new Player("Cherno");
    //printName(p);

    //Print(e);
    //Print(p);
    //or we can call a print() function like this
    //Print(new A());

    QThread::msleep(10000);

    int value = a.exec();



    return value;
}
