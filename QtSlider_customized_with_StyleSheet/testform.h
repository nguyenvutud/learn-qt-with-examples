#ifndef TESTFORM_H
#define TESTFORM_H

#include <QtWidgets/QWidget>
#include <QLabel>
#include "customized_slider.h"


namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = nullptr);
    ~TestForm();
private slots:
    void updateSizeOfAll();
protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *e);


private:
    Ui::TestForm *ui;
    CustomizedSlider *slider;
    QLabel *label;
};

#endif // TESTFORM_H
