/********************************************************************************
** Form generated from reading UI file 'set_configration.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_CONFIGRATION_H
#define UI_SET_CONFIGRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_set_configration
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_19;
    QLabel *label_53;
    QComboBox *comboPersonID;
    QLabel *label_54;
    QComboBox *comboPersonName_2;
    QCheckBox *checkBox;
    QComboBox *comboTaskID_2;
    QLabel *label_56;
    QComboBox *comboPersonName_3;
    QLabel *label_55;
    QComboBox *comboPersonName_4;
    QLabel *label_57;
    QGroupBox *groupBox_20;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_67;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *set_configration)
    {
        if (set_configration->objectName().isEmpty())
            set_configration->setObjectName(QString::fromUtf8("set_configration"));
        set_configration->resize(787, 625);
        buttonBox = new QDialogButtonBox(set_configration);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(420, 560, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox_19 = new QGroupBox(set_configration);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(10, 10, 751, 281));
        label_53 = new QLabel(groupBox_19);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(20, 50, 80, 21));
        comboPersonID = new QComboBox(groupBox_19);
        comboPersonID->setObjectName(QString::fromUtf8("comboPersonID"));
        comboPersonID->setGeometry(QRect(120, 50, 181, 31));
        comboPersonID->setMinimumSize(QSize(100, 0));
        label_54 = new QLabel(groupBox_19);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(20, 110, 80, 21));
        comboPersonName_2 = new QComboBox(groupBox_19);
        comboPersonName_2->setObjectName(QString::fromUtf8("comboPersonName_2"));
        comboPersonName_2->setGeometry(QRect(120, 110, 181, 31));
        comboPersonName_2->setMinimumSize(QSize(100, 0));
        checkBox = new QCheckBox(groupBox_19);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(430, 110, 211, 27));
        comboTaskID_2 = new QComboBox(groupBox_19);
        comboTaskID_2->setObjectName(QString::fromUtf8("comboTaskID_2"));
        comboTaskID_2->setGeometry(QRect(430, 50, 181, 31));
        comboTaskID_2->setMinimumSize(QSize(100, 0));
        label_56 = new QLabel(groupBox_19);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(330, 50, 80, 21));
        comboPersonName_3 = new QComboBox(groupBox_19);
        comboPersonName_3->setObjectName(QString::fromUtf8("comboPersonName_3"));
        comboPersonName_3->setGeometry(QRect(190, 180, 181, 31));
        comboPersonName_3->setMinimumSize(QSize(100, 0));
        label_55 = new QLabel(groupBox_19);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(20, 180, 171, 21));
        comboPersonName_4 = new QComboBox(groupBox_19);
        comboPersonName_4->setObjectName(QString::fromUtf8("comboPersonName_4"));
        comboPersonName_4->setGeometry(QRect(190, 230, 181, 31));
        comboPersonName_4->setMinimumSize(QSize(100, 0));
        label_57 = new QLabel(groupBox_19);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(20, 230, 171, 21));
        groupBox_20 = new QGroupBox(set_configration);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(10, 320, 751, 221));
        label_63 = new QLabel(groupBox_20);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(20, 50, 101, 21));
        label_64 = new QLabel(groupBox_20);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(20, 110, 121, 21));
        label_65 = new QLabel(groupBox_20);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(350, 50, 80, 21));
        label_66 = new QLabel(groupBox_20);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(20, 180, 171, 21));
        label_67 = new QLabel(groupBox_20);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(360, 170, 171, 21));
        lineEdit = new QLineEdit(groupBox_20);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 50, 171, 29));
        lineEdit_2 = new QLineEdit(groupBox_20);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(400, 50, 191, 29));
        lineEdit_3 = new QLineEdit(groupBox_20);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 110, 171, 29));
        lineEdit_4 = new QLineEdit(groupBox_20);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 170, 171, 29));
        lineEdit_5 = new QLineEdit(groupBox_20);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(520, 170, 171, 29));
        checkBox_3 = new QCheckBox(groupBox_20);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(360, 110, 211, 27));

        retranslateUi(set_configration);
        QObject::connect(buttonBox, SIGNAL(accepted()), set_configration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), set_configration, SLOT(reject()));

        QMetaObject::connectSlotsByName(set_configration);
    } // setupUi

    void retranslateUi(QDialog *set_configration)
    {
        set_configration->setWindowTitle(QApplication::translate("set_configration", "Dialog", nullptr));
        groupBox_19->setTitle(QApplication::translate("set_configration", "Person Info", nullptr));
        label_53->setText(QApplication::translate("set_configration", "Person ID", nullptr));
        label_54->setText(QApplication::translate("set_configration", "Name", nullptr));
        checkBox->setText(QApplication::translate("set_configration", "Left Handed", nullptr));
        label_56->setText(QApplication::translate("set_configration", "Task ID", nullptr));
        label_55->setText(QApplication::translate("set_configration", "Lefthand Device ID", nullptr));
        label_57->setText(QApplication::translate("set_configration", "Righthand Device ID", nullptr));
        groupBox_20->setTitle(QApplication::translate("set_configration", "Database Info", nullptr));
        label_63->setText(QApplication::translate("set_configration", "IP Address", nullptr));
        label_64->setText(QApplication::translate("set_configration", "Measurement", nullptr));
        label_65->setText(QApplication::translate("set_configration", "Port", nullptr));
        label_66->setText(QApplication::translate("set_configration", "DB Bucket", nullptr));
        label_67->setText(QApplication::translate("set_configration", "Validation Bucket", nullptr));
        checkBox_3->setText(QApplication::translate("set_configration", "Save to DB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_configration: public Ui_set_configration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_CONFIGRATION_H
