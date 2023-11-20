#ifndef CUSTOMIZEDSLIDER_H
#define CUSTOMIZEDSLIDER_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class CustomizedSlider; }
QT_END_NAMESPACE

class CustomizedSlider : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CustomizedSlider
     * @param parent
     */
    CustomizedSlider(QWidget *parent = nullptr);
    ~CustomizedSlider();

public slots:

    /**
     * @brief videoPositionChanged
     * @param position
     */
    void videoPositionChanged(qint64 position);

    /**
     * @brief videoDurationChanged
     * @param duration
     */
    void videoDurationChanged(qint64 duration);
    /**
     * @brief setLeftSliderSpacer
     * @param value
     */
    void setLeftSliderSpacer(int value);
    /**
     * @brief setRightSliderSpacer
     * @param value
     */
    void setRightSliderSpacer(int value);

signals:
    void setVideoPosition(int postions);

private slots:
    void updateDurationInfo(qint64 progress);

private:
    Ui::CustomizedSlider *ui;
    qint64 m_duration;
};
#endif // CUSTOMIZEDSLIDER_H
