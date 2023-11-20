#ifndef DIALOG_H
#define DIALOG_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include "myjob.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void onStop();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();
public slots:
    void onNumberChanged(QString name, int number);

private:
    Ui::Dialog *ui;
    MyJob myJob;
};
#endif // DIALOG_H
