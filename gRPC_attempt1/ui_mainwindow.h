/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPerform;
    QLabel *label;
    QRadioButton *rbtnInit;
    QTextBrowser *txtResults;
    QRadioButton *rbtnConfig;
    QRadioButton *rbtnEndRequest;
    QRadioButton *rbtnId;
    QRadioButton *rbtnEndSession;
    QPushButton *btnCollectData;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(601, 672);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnPerform = new QPushButton(centralwidget);
        btnPerform->setObjectName(QString::fromUtf8("btnPerform"));
        btnPerform->setGeometry(QRect(465, 570, 121, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 280, 80, 21));
        rbtnInit = new QRadioButton(centralwidget);
        rbtnInit->setObjectName(QString::fromUtf8("rbtnInit"));
        rbtnInit->setGeometry(QRect(70, 60, 181, 27));
        rbtnInit->setChecked(true);
        txtResults = new QTextBrowser(centralwidget);
        txtResults->setObjectName(QString::fromUtf8("txtResults"));
        txtResults->setGeometry(QRect(70, 320, 521, 241));
        rbtnConfig = new QRadioButton(centralwidget);
        rbtnConfig->setObjectName(QString::fromUtf8("rbtnConfig"));
        rbtnConfig->setGeometry(QRect(70, 100, 181, 27));
        rbtnEndRequest = new QRadioButton(centralwidget);
        rbtnEndRequest->setObjectName(QString::fromUtf8("rbtnEndRequest"));
        rbtnEndRequest->setGeometry(QRect(70, 140, 181, 27));
        rbtnId = new QRadioButton(centralwidget);
        rbtnId->setObjectName(QString::fromUtf8("rbtnId"));
        rbtnId->setGeometry(QRect(70, 230, 181, 27));
        rbtnEndSession = new QRadioButton(centralwidget);
        rbtnEndSession->setObjectName(QString::fromUtf8("rbtnEndSession"));
        rbtnEndSession->setGeometry(QRect(70, 190, 181, 27));
        btnCollectData = new QPushButton(centralwidget);
        btnCollectData->setObjectName(QString::fromUtf8("btnCollectData"));
        btnCollectData->setGeometry(QRect(340, 570, 106, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 601, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnPerform->setText(QApplication::translate("MainWindow", "Send Request", nullptr));
        label->setText(QApplication::translate("MainWindow", "Result:", nullptr));
        rbtnInit->setText(QApplication::translate("MainWindow", "Inititial Resquest", nullptr));
        rbtnConfig->setText(QApplication::translate("MainWindow", "Config Resquest", nullptr));
        rbtnEndRequest->setText(QApplication::translate("MainWindow", "End Resquest", nullptr));
        rbtnId->setText(QApplication::translate("MainWindow", "Get ID", nullptr));
        rbtnEndSession->setText(QApplication::translate("MainWindow", "End Session", nullptr));
        btnCollectData->setText(QApplication::translate("MainWindow", "Collect Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
