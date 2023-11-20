#include <QFrame>
#include <QDebug>
#include <QVBoxLayout>

#include "custom_dialog.h"
#include "ui_custom_dialog.h"

CustomDialog::CustomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    //main frame of window is transparent
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_TranslucentBackground);
    mDisplayTime = 5;
    connect(ui->btnDialogOk,SIGNAL(clicked()), this, SLOT(onTimerStoppted()));
    connect(ui->btnDialogCancel,SIGNAL(clicked()), this, SLOT(onTimerStoppted()));
}

CustomDialog::~CustomDialog()
{
    onTimerStoppted();
    delete ui;
}

void CustomDialog::setDisplayTime(int displayTime)
{
    mDisplayTime = displayTime;
}

void CustomDialog::changeEvent(QEvent *e)
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
void CustomDialog::setButtonName(QString okBtnName, QString cancelBtnName)
{
    QString space = "   ";
    ui->btnDialogOk->setText(space + okBtnName + space);

    ui->btnDialogOk->setVisible(okBtnName != "" ? true : false);

    ui->btnDialogCancel->setText(space + cancelBtnName + space);

    ui->btnDialogCancel->setVisible(cancelBtnName != "" ? true : false);

}

void CustomDialog::setText(QString text)
{
    ui->lblDialogContent->setText(text);
}

void CustomDialog::setTitle(QString text)
{
    ui->lblDialogTitle->setText(text);
    ui->lblDialogTitle->setVisible(text != "" ? true : false);
}

int CustomDialog::showDialog(bool modal=true)
{
    connect(&mTimer, SIGNAL(timeout()), this, SLOT(onDisplayTimeCounted()));
    mTimer.start(1000);
    if(modal)
    {
        this->setModal(true);
        return this->exec();
    }
    else
    {
        this->show();
        return CustomDialog::Rejected;
    }
}

void CustomDialog::setBackground(QString style)
{
    if(style=="")
    {
        ui->frameDialog->setStyleSheet("QFrame#frameDialog{background-color: transparent; border-image: url(:/images/images/Popup_white.svg);}");
    }
    else{
        ui->frameDialog->setStyleSheet(style);
    }
}

void CustomDialog::setPureGeometry(QRect rect)
{
    mRect = rect;
    this->setGeometry(mRect);
}

void CustomDialog::setRelativePosition(QPoint point)
{
    this->move(QPoint(mRect.x(), mRect.y()) + point);
}

void CustomDialog::visibleClosingButton(bool visible)
{
    ui->btnDialogClosing->setVisible(visible);
}

void CustomDialog::onDisplayTimeCounted()
{
    mDisplayTime -= 1;
    if(mDisplayTime < 0)
    {
        this->close();
    }
}

void CustomDialog::onTimerStoppted()
{
    mTimer.stop();
}

void CustomDialog::on_btnDialogClosing_clicked()
{
    onTimerStoppted();
    close();
}

