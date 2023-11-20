#ifndef SET_CONFIGRATION_H
#define SET_CONFIGRATION_H

#include <QtWidgets/QDialog>

namespace Ui {
class set_configration;
}

class set_configration : public QDialog
{
    Q_OBJECT

public:
    explicit set_configration(QWidget *parent = nullptr);
    ~set_configration();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::set_configration *ui;
};

#endif // SET_CONFIGRATION_H
