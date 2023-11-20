#include "machineinfo.h"
#include "ui_machineinfo.h"

MachineInfo::MachineInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachineInfo)
{
    ui->setupUi(this);
}

MachineInfo::~MachineInfo()
{
    delete ui;
}

void MachineInfo::changeEvent(QEvent *e)
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

void MachineInfo::on_btnInfoHome_clicked()
{
    emit HomeClicked();
}
