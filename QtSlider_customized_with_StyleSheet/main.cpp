#include "customized_slider.h"
#include "mainform.h"
#include "testform.h"
#include "testqgraphicsvideoitem.h"
#include "testgraphicsproxywidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Using QVideoWidget to display the video
//    MainForm w;
//    TestForm w;
    //Using QGraphicsView and QGraphicsViedeoItem to display video
    TestQGraphicsVideoItem w;
    w.showMaximized();
    //using QGraphicsProxy to display other widgets on the top of video
    //can't not work
//    TestGraphicsProxyWidget w;
//    w.show();
    return a.exec();
}
