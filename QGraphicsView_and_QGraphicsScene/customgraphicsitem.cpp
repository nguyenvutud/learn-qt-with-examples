#include "customgraphicsitem.h"
#include "ui_customgraphicsitem.h"

CustomGraphicsItem::CustomGraphicsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomGraphicsItem)
{
    ui->setupUi(this);
}

CustomGraphicsItem::~CustomGraphicsItem()
{
    delete ui;
}

void CustomGraphicsItem::changeEvent(QEvent *e)
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
