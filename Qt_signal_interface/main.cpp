#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Testing...";

    return a.exec();
}
