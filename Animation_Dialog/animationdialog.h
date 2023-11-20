#ifndef ANIMATIONDIALOG_H
#define ANIMATIONDIALOG_H

#include <QtWidgets/QDialog>


namespace Ui {
class AnimationDialog;
}

class AnimationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationDialog(QWidget *parent = nullptr);
    ~AnimationDialog();

    void animate(bool reverse = false);

    void done(int r) override;
    void open() override;

protected:
    void changeEvent(QEvent *e);

    signals:
        void reverseAnimStarted();

private slots:
        void on_pushButton_clicked();

private:
        bool animation_on = false;

private:
    Ui::AnimationDialog *ui;
};

#endif // ANIMATIONDIALOG_H
