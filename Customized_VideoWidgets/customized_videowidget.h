#ifndef CUSTOMIZED_VIDEOWIDGET_H
#define CUSTOMIZED_VIDEOWIDGET_H

#include <QtWidgets/QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>

#include <QProgressBar>
#include <QLabel>


namespace Ui {
class CustomizedVideoWidget;
}

class CustomizedVideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    explicit CustomizedVideoWidget(QWidget *parent = nullptr);
    ~CustomizedVideoWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CustomizedVideoWidget *ui;
    QVideoWidget *m_videoWidget = nullptr;
    QMediaPlayer *m_videoPlayer = nullptr;
    QProgressBar *m_progressBar = nullptr;
    QLabel *m_videoTimeLabel = nullptr;

};

#endif // CUSTOMIZED_VIDEOWIDGET_H
