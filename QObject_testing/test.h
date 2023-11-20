#ifndef TEST_H
#define TEST_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QDebug>

class Test: public QObject
{
    //You're not officially a QObject unless you have this.
    //And this goes into the build process through the meta object compiler
    //and it'll go through and add a bunch of special code for us
    Q_OBJECT
public:
    //parent = nullptr: parent here is QObject will delete all children
    explicit Test(QObject *parent = nullptr);

signals:
    void close();
public slots:
    void doStuff();

};

#endif // TEST_H
