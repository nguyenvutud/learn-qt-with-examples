#ifndef TESTQGRAPHICSVIDEOITEM_H
#define TESTQGRAPHICSVIDEOITEM_H

#include <QtWidgets/QWidget>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "customized_slider.h"

namespace Ui {
class TestQGraphicsVideoItem;
}

class TestQGraphicsVideoItem : public QWidget
{
    Q_OBJECT

public:
    explicit TestQGraphicsVideoItem(QWidget *parent = nullptr);
    ~TestQGraphicsVideoItem();

    QSize sizeHint() const override;

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void showSlider();

    void setVideoPosition(int position);
signals:
    void videoDurationChanged(qint64);

private:
    Ui::TestQGraphicsVideoItem *ui;
    QMediaPlayer *m_mediaPlayer = nullptr;
    QGraphicsVideoItem *m_videoItem = nullptr;

    CustomizedSlider *slider = nullptr;

};

#endif // TESTQGRAPHICSVIDEOITEM_H
