#include "datacollection.h"
#include "ui_datacollection.h"

DataCollection::DataCollection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataCollection)
{
    ui->setupUi(this);
}

DataCollection::~DataCollection()
{
    delete ui;
}

void DataCollection::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
