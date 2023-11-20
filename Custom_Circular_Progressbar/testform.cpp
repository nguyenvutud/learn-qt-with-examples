#include "testform.h"
#include "ui_testform.h"
#include "circular_progressbar.h"
#include <QHBoxLayout>

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);

    CircularProgressBar *c1 = new CircularProgressBar(this);
    CircularProgressBar *c2 = new CircularProgressBar(this);
    CircularProgressBar *c3 = new CircularProgressBar(this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(c1);
    ui->frame1->setLayout(layout1);
    c1->setProgressColor("red");
    c1->setInnerFontSize(40);
    c1->setValue(30);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(c2);
    c2->setValue(100);
    c2->setInnerValue(false);
    c2->setInnerImage(true);
    c2->setInnerImagePath(":/icon/icons/Gesture_next.svg");
    c2->setInnerImageSize(529, 736);
    ui->frame2->setLayout(layout2);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(c3);
    c3->setProgressWidth(15);
    c3->setRestProgressColor("#d7d7d7");
    ui->frame3->setLayout(layout3);

}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::changeEvent(QEvent *e)
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
