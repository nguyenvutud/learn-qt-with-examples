#include "set_configration.h"
#include "ui_set_configration.h"

set_configration::set_configration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set_configration)
{
    ui->setupUi(this);
}

set_configration::~set_configration()
{
    delete ui;
}

void set_configration::changeEvent(QEvent *e)
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
