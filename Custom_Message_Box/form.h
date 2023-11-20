#ifndef FORM_H
#define FORM_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QWidget>
#endif

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Form *ui;
};

#endif // FORM_H
