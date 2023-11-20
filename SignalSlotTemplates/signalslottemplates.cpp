#include "signalslottemplates.h"
#include "ui_signalslottemplates.h"

SignalSlotTemplates::SignalSlotTemplates(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignalSlotTemplates)
{
    ui->setupUi(this);

    QObject::connect(ui->btnAdd, &QPushButton::clicked,
                     this, &SignalSlotTemplates::onAddItemClick);

    // connect listener for when an item is added
    QObject::connect(&mItems, &ListSS::itemAdded,
                     this, &SignalSlotTemplates::onAddedItem);

    // Connect clear list button to clear Item list.
    // If we use this connection, we don't really need the virtual function in ListSS
    // we can remove clear() func in ListSS and override
    // But we have to set the 4th param: &List<QString>::clear
//    QObject::connect(ui->btnClear, &QPushButton::clicked,
//                     &mItems, &ListSS::clear);

    // If we use this connection, we need a virtual function in ListSS
    QObject::connect(ui->btnClear, SIGNAL(clicked()),
                     &mItems, SLOT(clear()));



    //Connect listener for when the list is cleared
    QObject::connect(&mItems, &ListSS::cleared,
                     this, &SignalSlotTemplates::onCleared);
}

SignalSlotTemplates::~SignalSlotTemplates()
{
    delete ui;
}

void SignalSlotTemplates::onAddItemClick()
{
    int intValue = 10; //we have to change the type of mItems
    QString strValue = "Hello World";
    mItems.appendItem(intValue);
}

void SignalSlotTemplates::onAddedItem(){
    QString txt = tr("Added Item: %1").arg(mItems.getPlaceHolder());
    ui->textEdit->setText(txt);
}

void SignalSlotTemplates::onCleared(){
    ui->textEdit->setText("List is cleared");
}

