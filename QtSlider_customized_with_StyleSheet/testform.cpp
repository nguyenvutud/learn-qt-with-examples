#include "testform.h"
#include "ui_testform.h"
#include <QVBoxLayout>
#include <QLabel>

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);
    slider = new CustomizedSlider(this);
    slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout(this);
//    layout->addWidget(slider);

    label = new QLabel("THIS IS A TEXT");
    layout->addWidget(label);

    ui->frame->setLayout(layout);

    updateSizeOfAll();
}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::updateSizeOfAll()
{
    QRect rect = this->geometry();

    rect.setWidth(600);
    rect.setHeight(400);

    rect.setY(250);

    slider->setGeometry(rect);



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

void TestForm::resizeEvent(QResizeEvent *e)
{
//    QRect rect = ui->frame->geometry();

//    rect.setY(rect.height() - 100);

//    slider->setGeometry(rect);
}
