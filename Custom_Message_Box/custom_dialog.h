#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include <QPainter>
#include <QTimer>
#include <QPoint>

namespace Ui {
class CustomDialog;
}

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomDialog(QWidget *parent = nullptr);
    ~CustomDialog();
    void setDisplayTime(int displayTime=0);

public slots:
    void setButtonName(QString okBtnName="Ok", QString cancelBtnName="Cancel");
    void setText(QString text);
    void setTitle(QString text);
    int showDialog(bool modal);

    void setBackground(QString style);

    void setPureGeometry(QRect rect);
    void setRelativePosition(QPoint point);

    void visibleClosingButton(bool visible=true);

    void onDisplayTimeCounted();
    void onTimerStoppted();

protected:
    void changeEvent(QEvent *e);
private slots:
    void on_btnDialogClosing_clicked();

private:
    Ui::CustomDialog *ui;
    int mDisplayTime;
    QTimer mTimer;
    QRect mRect;


};

#endif // DIALOG_H
