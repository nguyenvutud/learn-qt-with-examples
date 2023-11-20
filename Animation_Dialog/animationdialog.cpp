#include "animationdialog.h"
#include "ui_animationdialog.h"
#include <QPropertyAnimation>

AnimationDialog::AnimationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimationDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    connect(this, &AnimationDialog::reverseAnimStarted,
    [this] {animation_on = true; });
}

AnimationDialog::~AnimationDialog()
{
    delete ui;
}

void AnimationDialog::animate(bool reverse)
{
    auto animFade= new QPropertyAnimation(this, "windowOpacity", this);
    animFade->setDuration(400);
    animFade->setEasingCurve(QEasingCurve::Linear);

    auto pos1 = QPoint{ (parentWidget()->pos().x() + parentWidget()->width() / 2 - width() / 2) + 15,
        (parentWidget()->pos().y() + parentWidget()->height() + height() / 2) / 2 };

    auto pos2 = QPoint{ (parentWidget()->pos().x() + parentWidget()->width() / 2 - width() / 2) + 15,
        (parentWidget()->pos().y() + parentWidget()->height() + height() / 2) / 2 - 65 };

    auto animMove = new QPropertyAnimation(this, "pos", this);
    animMove->setDuration(500);
    animMove->setEasingCurve(QEasingCurve::OutQuad);

    if (!reverse) {
        animFade->setStartValue(0.0);
        animFade->setEndValue(1.0);
        animMove->setStartValue(pos2);
        animMove->setEndValue(pos1);

    } else {
        emit reverseAnimStarted();
        animFade->setStartValue(1.0);
        animFade->setEndValue(0.0);
        animMove->setStartValue(pos1);
        animMove->setEndValue(pos2);

        connect(animFade, &QPropertyAnimation::finished,
            [this] { QDialog::hide(); });
    }

    animFade->start(QAbstractAnimation::DeleteWhenStopped);
    animMove->start(QAbstractAnimation::DeleteWhenStopped);
}

void AnimationDialog::done(int r)
{
    if (!animation_on) {
        animate(true);
        setResult(r);
        if (r == QDialog::Accepted)
            emit accepted();
        else if (r == QDialog::Rejected)
            emit rejected();

        emit finished(r);
    }
}

// override showEvent if you call show instead
void AnimationDialog::open()
{
    animate(false);
    QDialog::open();
}

void AnimationDialog::changeEvent(QEvent *e)
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

void AnimationDialog::on_pushButton_clicked()
{
    close();
}
