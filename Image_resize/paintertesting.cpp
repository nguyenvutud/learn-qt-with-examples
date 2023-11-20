#include "paintertesting.h"
#include "ui_paintertesting.h"
#include <QPainter>
#include <QDebug>

PainterTesting::PainterTesting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PainterTesting)
{

    ui->setupUi(this);

//    QPalette* palette = new QPalette();
//    QPixmap* pixmap = new QPixmap(":/images/popup1.svg");
//    QBrush* brush = new QBrush(*pixmap);

//    palette->setBrush(QPalette::Background, *brush);

//    ui->lblPic->setPalette(*palette);

    QPixmap pixmap(":/images/popup_white.svg");
    //scaled the size
    int w = 261;
    int h = 240;

    QImage image(":/images/popup_white.svg");
    ui->lblPic->setPixmap(QPixmap::fromImage(image));
    //ui->lblPic->setPixmap(pixmap);
}

PainterTesting::~PainterTesting()
{
    delete ui;
}

void PainterTesting::paintEvent(QPaintEvent *pe)
{
    qInfo() << "Paint event";
//    QPainter painter(this);

//    auto winSize = size();
//    auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
//    auto windowRatio = (float)winSize.width() / winSize.height();

//    if(pixmapRatio > windowRatio)
//    {
//      auto newWidth = (int)(winSize.height() * pixmapRatio);
//      auto offset = (newWidth - winSize.width()) / -2;
//      painter.drawPixmap(offset, 0, newWidth, winSize.height(), _pixmapBg);
//    }
//    else
//    {
//      auto newHeight = (int)(winSize.width() / pixmapRatio);
//      auto offset = (newHeight - winSize.height()) / -2;
//      painter.drawPixmap(0, offset, winSize.width(), newHeight, _pixmapBg);
    //    }
}

void PainterTesting::resizeEvent(QResizeEvent *e)
{
    QImage image(":/images/popup_white.svg");
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap.scaled(ui->lblPic->width(), ui->lblPic->height());
    ui->lblPic->setPixmap(pixmap);
}

void PainterTesting::changeEvent(QEvent *e)
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
