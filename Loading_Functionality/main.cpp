#include <QDebug>
#include <QScreen>
#include <QDesktopWidget>

#include "mainwindow.h"
#include "loading_dialog.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif

static void staticFunction()
{
    QTimer::singleShot(1000,[]()->void{qDebug("Hello World!");});
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int width = w.frameGeometry().width();
    int height = w.frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    w.setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
    w.show();
    w.hide();
    //staticFunction();

    LoadingDialog loadingDial;
    loadingDial.showLoadingFunc(100, 3000);
    w.show();
    return a.exec();
}

