#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

#include "mainwindow.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMediaPlayer * player = new QMediaPlayer;

    QVideoWidget* vw = new QVideoWidget;

    player->setVideoOutput(vw);

    player->setMedia(QUrl::fromLocalFile("/home/vunguyen/Videos/test.mp4"));

    vw->setGeometry(100, 100, 300, 400);

    vw->show();

    player->play();

    qInfo() << player->state();
    //w.show();
    return a.exec();
}
