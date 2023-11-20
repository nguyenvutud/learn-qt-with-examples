#include "testgraphicsproxywidget.h"
#include "ui_testgraphicsproxywidget.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QVideoWidget>

#include <QFileDialog>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QDebug>

TestGraphicsProxyWidget::TestGraphicsProxyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestGraphicsProxyWidget)
{
    ui->setupUi(this);
    const QSizeF VideoItemSize(500, 500);

    QMediaPlayer player;
    QGraphicsScene scene;
    QGraphicsVideoItem video;
    ui->graphicsView->setScene(&scene);
    video.setSize(VideoItemSize);
    scene.setSceneRect(QRectF(QPointF(0, 0), VideoItemSize)); // VideoItem full fill the scene
    scene.addItem(&video);
    player.setVideoOutput(&video);
    player.setMedia(QMediaContent(QFileDialog::getOpenFileUrl()));

    // Recommend using QGraphicsItems for overlay component
    QGraphicsTextItem text("Loading...",&video);
    text.setPos(100, 150);

    // If you need a button...
    QPushButton button("ButtonTest");
    QGraphicsProxyWidget* proxyButton = scene.addWidget(&button);
    proxyButton->setPos(100, 200);

    // Instead of QGraphicsItems, if you really need a QWidget...
    QLabel label("LabelTest");
    //label.setAttribute(Qt::WA_TranslucentBackground); // You can delete this line to see different
    QGraphicsProxyWidget* proxyLabel = scene.addWidget(&label);
    proxyLabel->setPos(100, 250);


    player.play();

    QVideoWidget *videoWidget = new QVideoWidget(this);
    ui->graphicsView->setViewport(videoWidget);
    player.setVideoOutput(videoWidget);

    ui->graphicsView->show();

    qInfo() << "Video status:" << player.state();
    qInfo() << "Video duration:" << player.duration();
}

TestGraphicsProxyWidget::~TestGraphicsProxyWidget()
{
    delete ui;
}

void TestGraphicsProxyWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
