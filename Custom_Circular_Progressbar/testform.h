#ifndef TESTFORM_H
#define TESTFORM_H

#include <QtWidgets/QWidget>


namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = nullptr);
    ~TestForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TestForm *ui;
};

#endif // TESTFORM_H
