#ifndef DIALOG1_H
#define DIALOG1_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QDialog>
#endif

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
