#include "seconddialog.h"
#include "ui_seconddialog.h"

#include <QPixmap> //for picture in Label

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/sources/img/pic.jpg");
    int w = ui->lblPicture->width();
    int h = ui->lblPicture->height();
    ui->lblPicture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

SecondDialog::~SecondDialog()
{
    delete ui;
}
