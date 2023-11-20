#include "mainwindow.h"
#include "mydialog.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#include <QPropertyAnimation>
#else
#include <QtGui/QApplication>
#endif

/// link: https://stackoverflow.com/questions/29031597/implementing-fade-in-fade-out-for-a-modal-qdialog
///

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ///Ex 1:
//    MyDialog w;
//    int ret = w.exec();
    ///Ex 2:
    MainWindow w;
    w.show();
    return a.exec();
}
