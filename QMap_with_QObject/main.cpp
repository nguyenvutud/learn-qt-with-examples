#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>
#include "cat.h"

//cateing a QMap

typedef QMap<QString, QSharedPointer<Cat>> catMap;

catMap getCats()
{
    catMap cats;

    for(int i = 0; i < 5; i++)
    {
        //using QSharedPointer basically when cat is no longer needed
        //QSharedPointer will aumatically delete it, make memory management

         QSharedPointer<Cat> ptr(new Cat());
        ptr->setAge(QRandomGenerator::global()->bounded(1, 5));
        ptr->setName("Unknown");

        cats.insert("pet"+QString::number(i), ptr);
    }
    return cats;
}

//Displaying a QMap
void display(catMap &cats)
{
    foreach(QString key, cats.keys())
    {
        QSharedPointer<Cat> ptr = cats.value(key);
        qInfo() << key << ptr->name() << ptr->age() << ptr.data();
    }
}

//modifying an item
void modifyCat(catMap &cats, QString key)
{
    if(cats.contains(key))
    {
        qInfo() << "Modifying:" << key;
        cats[key]->setAge(99);
        cats[key]->setName("Fluffy");
        display(cats);
    }
}

//Adding and inserting
void addCat(catMap &cats)
{
    qInfo() << "Adding and inserting";
    QSharedPointer<Cat> ptr(new Cat());
    ptr->setAge(100);
    ptr->setName("Test Cat");
    cats.insert("test", ptr);// prefer to doing this
//    cats["test"] = ptr; //will not check whether "test" is existing or not
    display(cats);
}

//Searching for an item
void findCat(catMap &cats, QString key){
    qInfo() << "Exist:" << cats.contains(key);
    auto iter = cats.find(key);
    if(iter != cats.end()){
        qInfo() << iter.key() << iter.value();
    }

    foreach(QSharedPointer<Cat> value, cats.values())
    {
        qInfo() << value;
    }

    foreach(QString key, cats.keys())
    {
        qInfo() << "Key:"<< key << "Value:" << cats.value(key);
    }
}

//Removing an item

void removeCat(catMap &cats, QString key)
{
    if(!cats.contains(key)){
        qWarning() << "Cat not found";
        return;
    }
    cats.remove(key);
    display(cats);

}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Intro

    QMap<QString, double> lucky;
    lucky.insert(QString("Bryan"), 22.5);
    qInfo() << lucky;
    qInfo() << "My Lucky number:" << lucky["Bryan"];

    //creating a QMap
    catMap cats = getCats();
    qInfo() << cats;

    //displaying
    display(cats);

    //modifying Cat
    modifyCat(cats, "pet2");

    //adding
    addCat(cats);
    addCat(cats);//will

    //finding

    findCat(cats, "test");

    //removing

    removeCat(cats, "test");

    //cleanup
    qInfo() << "Cleaning...";
    cats.clear();

    return a.exec();
}
