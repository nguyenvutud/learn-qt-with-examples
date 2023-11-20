#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>


///https://www.youtube.com/watch?v=oIV2KchSyGQ&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=27
///
///
class Entity
{
private:
    int x, y;
public:
    void Move(int xx, int yy){
        x += xx;
        y += yy;
    }
public:
    virtual QString getName() {return "Entity"; }

};

class Player: public Entity
{
private:
    QString mName;
public:
    Player(const QString& name):
        mName(name){}
    ///From c++11, it has this keyword override
    /// it should work well without this keyword
    /// But we use this keywork in order to
    /// make it a little bit more readable since we know
    /// this is actually an overriden function.
    /// Also it just helps us a little bit with preventing bugs tutors
    /// like spelling mistakes for example typying getname() with a lowercase
    /// because there's no such function in the base class for us to override
    ///
    /// Virtual functions aren't free though
    /// there are two runtime costs associated
    /// firstly we have additional memoriy that is required
    /// in order for us to store that table so that we can dispatch to the correct fucntion
    /// that includes a member pointer in the actual base path that points to the
    /// V-table and
    /// secondly everytime we call a virtual function we have to go through that table
    /// to determine which function to actually map to which is an additional performance penalty
    ///
    ///
    QString getName() override{return mName; }
    void playMusic(){
        qInfo() << "Playing mussic";
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Entity* e = new Entity();
    qInfo() << e->getName();

    Player* p = new Player("Vu");
    qInfo() << p->getName();

    /// If we don't use virtual func here, it will show the result of entity
    /// because getName() func in entity will be called
    Entity* entity = p;
    qInfo() << entity->getName();


    return a.exec();
}
