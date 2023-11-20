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
