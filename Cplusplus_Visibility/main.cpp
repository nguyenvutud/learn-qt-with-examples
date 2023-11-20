#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

///https://www.youtube.com/watch?v=6OVQ8nh3KP0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=29
///
/// There are three basic visibility modifiers that we have in c++
/// private, protected and public
///
/// The visibility is not about memory saving, computer. But it's about that humans have invented in order to
/// other human and themselves
///
/// Visibility helps people choosing the right order
/// such as if Player have an ability to change x, y instead of calling Move(x, y)
/// it might be wrong if they want actually move to new position x, y
///

class Entity{
private:
    int x, y;
public:
    Entity(x, y)
    {
        this->x = x;
        this->y = y;
    }
};

class Player: public Entity{

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
