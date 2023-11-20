#include "customized_videowidget.h"
#include "ui_customized_videowidget.h"

CustomizedVideoWidget::CustomizedVideoWidget(QWidget *parent) :
    QVideoWidget(parent),
    ui(new Ui::CustomizedVideoWidget)
{
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setPalette(p);

    setAttribute(Qt::WA_OpaquePaintEvent);

    m_videoPlayer = new QMediaPlayer(this);
    m_videoWidget = new QVideoWidget(this);

    m_videoPlayer->setVideoOutput(m_videoWidget);

    ui->videoPlayerLayout->addWidget(m_videoWidget);

    m_progressBar = new QProgressBar(this);
    ui->videoPlayerLayout->addWidget(m_progressBar);
}

CustomizedVideoWidget::~CustomizedVideoWidget()
{
    delete ui;
}

void CustomizedVideoWidget::changeEvent(QEvent *e)
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
