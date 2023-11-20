#include "mainform.h"
#include "ui_mainform.h"
#include "video_widget.h"

#include <QMediaControl>
#include <QVideoSurfaceFormat>



#include <QDebug>
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    slider = new CustomizedSlider(this);
    slider->setAutoFillBackground(false);
//    updateSliderGeo();
   slider->setGeometry(QRect(0, 450, 600, 400));

    videoWidget = new VideoWidget(this);


    videoWidget->setWindowFlag(Qt::FramelessWindowHint);
    videoWidget->setWindowFlag(Qt::NoDropShadowWindowHint);
    //main frame of window is transparent
    videoWidget->setAttribute(Qt::WA_NoSystemBackground);
    videoWidget->setAttribute(Qt::WA_TranslucentBackground);
    //videoWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

//    QPalette p = palette();
//    p.setColor(QPalette::Window, Qt::transparent);

//    videoWidget->setPalette(p);
//    videoWidget->setAttribute(Qt::WA_OpaquePaintEvent); //no background

    QMediaPlayer *player = new QMediaPlayer();

    QSizePolicy sizePolicy;
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
//    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    videoWidget->setSizePolicy(sizePolicy);


    player->setVideoOutput(videoWidget);

    ui->videoLayout->setGeometry(ui->frame_2->geometry());
    ui->videoLayout->addWidget(videoWidget);

//    slider->setGeometry(ui->frame_2->geometry());
//    slider->setAutoFillBackground(false);

    QString filename = "/home/vunguyen/Videos/test1.mp4";
    player->setMedia(QUrl::fromLocalFile(filename));

    player->play();
    player->setPosition(1);



}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::changeEvent(QEvent *e)
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

void MainForm::resizeEvent(QResizeEvent *e)
{
//   QRect rect = ui->frame_2->geometry();

//    rect.setY(rect.height() - 100);

//    slider->setGeometry(rect);

    QWidget::resizeEvent(e);
}

void MainForm::updateSliderGeo()
{
//       QRect rect = this->geometry();

//       rect.setWidth(600);
//       rect.setHeight(400);
//        rect.setY(450);
//    qInfo() << ui->pushButton->geometry();
//        slider->setGeometry(rect);
}
