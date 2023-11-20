#ifndef COUNTDOWN_DIALOG_H
#define COUNTDOWN_DIALOG_H
#include <QDialog>
#include <QTimer>

namespace Ui {
class CountDownDialog;
}

class CountDownDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CountDownDialog(QWidget *parent = nullptr);
    ~CountDownDialog();
    void start(int count);

protected:
    void changeEvent(QEvent *e);
private slots:
    void countDown();
    void setImage(QString path);

private:
    Ui::CountDownDialog *ui;
    QTimer *timer = nullptr;
    int m_count = 0;
};

#endif // COUNTDOWN_DIALOG_H
