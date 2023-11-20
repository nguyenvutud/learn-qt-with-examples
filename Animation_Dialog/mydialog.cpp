#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

int MyDialog::exec()
{
    this->setWindowOpacity(0.0);
    QPropertyAnimation* anim = new QPropertyAnimation(this, "windowOpacity");
    anim->setDuration(5000); // will take 5 seconds
    anim->setEasingCurve(QEasingCurve::OutBack); // just demonstration, there are a lot of curves to choose
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    return QDialog::exec();
}

void MyDialog::changeEvent(QEvent *e)
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
