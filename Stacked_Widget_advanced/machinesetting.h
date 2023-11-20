#ifndef MACHINESETTING_H
#define MACHINESETTING_H

#include <QtWidgets/QWidget>


namespace Ui {
class MachineSetting;
}

class MachineSetting : public QWidget
{
    Q_OBJECT

public:
    explicit MachineSetting(QWidget *parent = nullptr);
    ~MachineSetting();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_btnSettingHome_clicked();

private:
    Ui::MachineSetting *ui;

signals:
    void homeClicked();
};

#endif // MACHINESETTING_H
