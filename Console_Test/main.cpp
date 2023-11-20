#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Testing Console app...";

    return a.exec();
}
