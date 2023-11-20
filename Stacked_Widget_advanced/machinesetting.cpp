#include "machinesetting.h"
#include "ui_machinesetting.h"

MachineSetting::MachineSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachineSetting)
{
    ui->setupUi(this);
}

MachineSetting::~MachineSetting()
{
    delete ui;
}

void MachineSetting::changeEvent(QEvent *e)
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

void MachineSetting::on_btnSettingHome_clicked()
{
    emit homeClicked();
}
