#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>

/// https://www.youtube.com/watch?v=bP9z3H3cVMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=34
/// Mutable is kind of Const but actually can change so it's almost like mutable reverses the meaning of const
///
/// marking a class member is mutable means that
/// constants method inside that class can actually modify that member
///
/// using mutable with class members and it's to do with lambdas
///
class Entity{
private:
    QString mName;
    mutable int mDebugCount = 0;
    //mutable here means we're allowing constant method (the second const) to change this variable
public:
    Entity(QString name)
    {
        mName = name;
    }
    /// fist const
    /// second const is to indicate that we would not change mName
    ///
    const QString& getName() const{
        mDebugCount++; //we can not change this variable here because this is const func
        return mName;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const Entity e("Vu");
    qInfo() << e.getName();

    ///with lambdas context
    int x = 8;
    auto f = [=]() //& capture by reference. = capture by value
    {
        int y = x; //can't change x if capturing by =
        y++;
        qInfo() << QString::number(y);
    };
    //call lambda
    f();

    ///or we can use mutable, so that we can change x
    auto f2 = [=]() mutable
    {
        //with mutable here, it will create a local variable item
        x++;
        qInfo() << x;
    };
    f2();
    //x still 8 after performing f2()

    return a.exec();
}
