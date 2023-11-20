#ifndef LOADING_DIALOG_H
#define LOADING_DIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class LoadingDialog;
}

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = nullptr);
    ~LoadingDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoadingDialog *ui;
};

#endif // LOADING_DIALOG_H
