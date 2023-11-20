#ifndef MAINFORM_H
#define MAINFORM_H

#include <QVideoWidget>
#include <QMediaPlayer>

#include <QtWidgets/QWidget>
#include "customized_slider.h"

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *e);
private slots:
    void updateSliderGeo();

private:
    Ui::MainForm *ui;
    /// Just create and place the widget on the fly.
    /// Avoid using UI to place the widget because then the widget position
    /// is managed by the layouts.
    /// Remember to create the widget after of the dialog's initialization.
    /// If you don't take care about this the widget will be inserted at
    /// the bottom.
    CustomizedSlider *slider = nullptr;

    QVideoWidget *videoWidget;
};

#endif // MAINFORM_H
