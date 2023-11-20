#include "mainwindow.h"
#include "testform.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.setWindowFlag(Qt::FramelessWindowHint);
//    w.setAttribute(Qt::WA_TranslucentBackground);
    TestForm w;
    w.show();
    return a.exec();
}
