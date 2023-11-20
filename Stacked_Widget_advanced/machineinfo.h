#ifndef MACHINEINFO_H
#define MACHINEINFO_H


#include <QtWidgets/QWidget>


namespace Ui {
class MachineInfo;
}

class MachineInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MachineInfo(QWidget *parent = nullptr);
    ~MachineInfo();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_btnInfoHome_clicked();

signals:
    void HomeClicked();
private:
    Ui::MachineInfo *ui;
};

#endif // MACHINEINFO_H
