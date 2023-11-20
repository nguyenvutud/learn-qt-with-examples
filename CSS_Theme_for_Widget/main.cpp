#include "mainwindow.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //open qss file
//    QFile file("./Adaptic/Adaptic.qss");
    QFile file("./Irrorater/Irrorater.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet {QLatin1String(file.readAll())};

    //setup stylesheet
    a.setStyleSheet(styleSheet);
    w.show();
    return a.exec();
}
