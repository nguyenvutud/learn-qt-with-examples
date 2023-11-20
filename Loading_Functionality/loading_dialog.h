#ifndef LOADING_DIALOG_H
#define LOADING_DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QLabel>
#include <QPainter>

namespace Ui {
class LoadingDialog;
}

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = nullptr);
    ~LoadingDialog();
    int showLoadingFunc(int speed, int delay);

public slots:
    void setText(QString text);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoadingDialog *ui;
    int counter = 0;
    bool stop = false;
    QTimer *timer;

private slots:
    void rotateImage(QLabel *label, const bool clockwise=true);
    void runRotation();
    void setStop();
    void setTransparent();


};

#endif // LOADING_DIALOG_H
