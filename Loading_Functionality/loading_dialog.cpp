#include <QtMath>
#include <QDebug>
#include <QDesktopWidget>
#include <QPropertyAnimation>

#include "loading_dialog.h"
#include "ui_loading_dialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    //main frame of window is transparent
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_TranslucentBackground);

    ui->setupUi(this);
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}

void LoadingDialog::setStop()
{
    stop = true;
    timer->stop();
    this->close();
}

void LoadingDialog::setTransparent()
{

}

int LoadingDialog::showLoadingFunc(int speed, int delay)
{
//    int width = this->frameGeometry().width();
//    int height = this->frameGeometry().height();
//    QDesktopWidget wid;
//    int screenWidth = wid.screen()->width();
//    int screenHeight = wid.screen()->height();
//    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(runRotation()));
    timer->start(speed);

    QTimer *stopTimer = new QTimer(this);
    connect(stopTimer, SIGNAL(timeout()), this, SLOT(setStop()));
    stopTimer->start(delay);

    ///set animation when loading feature starts/stops
    QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setDuration(1000);

    connect(animation, &QPropertyAnimation::finished, [animation](){
        if (animation->direction() == QAbstractAnimation::Forward) {
            animation->setDirection(QAbstractAnimation::Backward);
            QTimer::singleShot(1000, [animation]{ animation->start(); });
        }
    });
    animation->start();
    this->setModal(true);
    qInfo() << "Performing exec Dialog";
    return this->exec();
}

void LoadingDialog::setText(QString text)
{
    ui->loadingContent->setText(text);
}

void LoadingDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LoadingDialog::rotateImage(QLabel *label, const bool clockwise)
{
    QPixmap original(*label->pixmap());
    int w = original.size().width();
    int h = original.size().height();
    // load original from your source or take it from somewhere
    QImage srcImg = original.toImage();
    QTransform tr;

    tr.translate(w/2, h/2);
    int angleRotation = 90;
    if(!clockwise)
        angleRotation = -angleRotation;
    tr.rotate(angleRotation);
    tr.translate(-w/2, -h/2);
    tr.scale(1., 1.);

    QImage dstImg = srcImg.transformed(tr); //, Qt::FastTransformation
    QPixmap dstPix = QPixmap::fromImage(dstImg); //New pixmap rotated

    label->setPixmap(dstPix);
}

void LoadingDialog::runRotation()
{
    rotateImage(ui->lblMagenta);
    rotateImage(ui->lblCyan, true);
    rotateImage(ui->lblYellow);
}

