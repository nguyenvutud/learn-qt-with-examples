#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QtWidgets/QDialog>
#include <QPropertyAnimation>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
    int exec();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
