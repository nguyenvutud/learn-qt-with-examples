#include "customized_slider.h"
#include "ui_customized_slider.h"
#include <QTime>
#include <QDebug>

CustomizedSlider::CustomizedSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomizedSlider)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::NoDropShadowWindowHint);
    //main frame of window is transparent
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->videoPostionSlider->setRange(0, 0);

    connect(ui->videoPostionSlider, &QAbstractSlider::sliderMoved,
            this, &CustomizedSlider::setVideoPosition);
}

CustomizedSlider::~CustomizedSlider()
{
    delete ui;
}


void CustomizedSlider::videoPositionChanged(qint64 position)
{
    if (!ui->videoPostionSlider->isSliderDown())
        ui->videoPostionSlider->setValue(position / 1000);

    updateDurationInfo(position / 1000);

}

void CustomizedSlider::videoDurationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    ui->videoPostionSlider->setMaximum(m_duration);

}


void CustomizedSlider::setLeftSliderSpacer(int value)
{
    ui->leftSliderSpacer->sizeHint().setWidth(value);
}

void CustomizedSlider::setRightSliderSpacer(int value)
{
    ui->rightSliderSpacer->sizeHint().setWidth(value);
}


void CustomizedSlider::updateDurationInfo(qint64 currentInfo)
{

    QString durationInfo;
    if( currentInfo || m_duration){
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
                          currentInfo % 60, (currentInfo * 1000) % 1000);

        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
                        m_duration % 60, (m_duration * 1000) % 1000);

        QString format = "mm:ss";
        if (m_duration > 3600)
            format = "hh:mm:ss";

        durationInfo = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    ui->lblVideoTime->setText(durationInfo);
}
