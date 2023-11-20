#include "testqgraphicsvideoitem.h"
#include "ui_testqgraphicsvideoitem.h"
#include <QSlider>
#include <QDebug>
#include <QLabel>


TestQGraphicsVideoItem::TestQGraphicsVideoItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestQGraphicsVideoItem)
{
    ui->setupUi(this);
    m_mediaPlayer = new QMediaPlayer(this); // removed: , QMediaPlayer::VideoSurface
    m_videoItem = new QGraphicsVideoItem();
    m_videoItem->setPos(0, 0);
    m_videoItem->setSize(QSizeF(400, 350));

    QGraphicsScene *scene= new QGraphicsScene(this);
    scene->addItem(m_videoItem);

    ui->graphicsView->setScene(scene);

    // disanable scollbar
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //set sizepolicy
    QSizePolicy sizePolicy;
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);

    m_mediaPlayer->setVideoOutput(m_videoItem);


    QString filename = "/home/vunguyen/Videos/test1.mp4";
    m_mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    m_mediaPlayer->setPosition(1);

    ui->graphicsView->show();

    //Note: video can play here. But could not show Duration
    // it only shows Duration in click event.Why???

    m_mediaPlayer->play();

    qInfo() << "Video duration in Constructor:" << m_mediaPlayer->duration();


}

TestQGraphicsVideoItem::~TestQGraphicsVideoItem()
{
    delete ui;
}

QSize TestQGraphicsVideoItem::sizeHint() const
{
    qInfo() << "size Hint called:";
    return (m_videoItem->size() * qreal(3) / qreal(2)).toSize();
}

void TestQGraphicsVideoItem::changeEvent(QEvent *e)
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

void TestQGraphicsVideoItem::resizeEvent(QResizeEvent *e)
{
    qInfo() << "graphicsView size:" << ui->graphicsView->geometry();
    QRect rect(ui->graphicsView->geometry());
    m_videoItem->setSize(QSizeF(rect.width(), rect.height()));

    QSizePolicy sizePolicy;
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);

    //IgnoreAspectratio: this will maximize the video screen according to
    //parent widget
    m_videoItem->setAspectRatioMode(Qt::IgnoreAspectRatio);

    qInfo() << "resizeEvent is called";
    QWidget::resizeEvent(e);
}

void TestQGraphicsVideoItem::paintEvent(QPaintEvent *e)
{
    qInfo() << "paintEvent called";
    showSlider();
    QWidget::paintEvent(e);
}


void TestQGraphicsVideoItem::on_pushButton_clicked()
{
    //could not show slider in showEvent() or resizeEvent(). Why?
//    showSlider();

    m_mediaPlayer->play();

    qInfo() << "Video Duration:" << m_mediaPlayer->duration();
    emit videoDurationChanged(m_mediaPlayer->duration());

    qInfo() << "media player info:" << m_mediaPlayer->state();

}

void TestQGraphicsVideoItem::on_pushButton_2_clicked()
{
     m_mediaPlayer->pause();
}

void TestQGraphicsVideoItem::showSlider()
{

    if (!slider)
    {
        slider = new CustomizedSlider(this);
    }

    connect(slider, &CustomizedSlider::setVideoPosition, this, &TestQGraphicsVideoItem::setVideoPosition);

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, slider, &CustomizedSlider::videoPositionChanged);
    connect(this, SIGNAL(videoDurationChanged(qint64)), slider, SLOT(videoDurationChanged(qint64)));


    QRect rect = ui->frame->geometry();

    rect.setY(rect.height() - 90 - 50);

    slider->setGeometry(rect);
    slider->show();
}

void TestQGraphicsVideoItem::setVideoPosition(int position)
{
    m_mediaPlayer->setPosition(position);
}
