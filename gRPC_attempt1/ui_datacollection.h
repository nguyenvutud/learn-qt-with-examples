/********************************************************************************
** Form generated from reading UI file 'datacollection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACOLLECTION_H
#define UI_DATACOLLECTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataCollection
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DataCollection)
    {
        if (DataCollection->objectName().isEmpty())
            DataCollection->setObjectName(QString::fromUtf8("DataCollection"));
        DataCollection->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../dev/mimetik/glove-sdk/icons/datacollection.png"), QSize(), QIcon::Normal, QIcon::On);
        DataCollection->setWindowIcon(icon);
        centralwidget = new QWidget(DataCollection);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DataCollection->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataCollection);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        DataCollection->setMenuBar(menubar);
        statusbar = new QStatusBar(DataCollection);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DataCollection->setStatusBar(statusbar);

        retranslateUi(DataCollection);

        QMetaObject::connectSlotsByName(DataCollection);
    } // setupUi

    void retranslateUi(QMainWindow *DataCollection)
    {
        DataCollection->setWindowTitle(QApplication::translate("DataCollection", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataCollection: public Ui_DataCollection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACOLLECTION_H
