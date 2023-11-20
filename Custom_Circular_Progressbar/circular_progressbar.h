#ifndef CIRCULAR_PROGRESSBAR_H
#define CIRCULAR_PROGRESSBAR_H

#include <QtWidgets/QWidget>

class CircularProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit CircularProgressBar(QWidget *parent = nullptr);
    ~CircularProgressBar();
    /**
     * @brief paintEvent
     * @param e
     */
    void paintEvent(QPaintEvent *e);



protected:
    //void changeEvent(QEvent *e);

public slots:

    /**
     * @brief Sets a value which will be shown on the circular progress bar
     * @param val the value will be set which must be between min and max
     */
    void setValue(qreal val){
        if (m_value == val) return;
        m_value = val;
        update();
    }

    /**
     * @brief setProgressWidth
     * @param width
     */
    void setProgressWidth(int width);

    /**
     * @brief setProgressColor
     * @param color
     */
    void setProgressColor(QString color);

    /**
     * @brief setInnerColor
     * @param color
     */
    void setInnerTextColor(QString color);

    /**
     * @brief Set InnerImage
     * @param hasImage true: has an image, false: no image
     */
    void setInnerImage(bool hasImage);

    /**
     * @brief Set InnerImage Size
     * @param w width of image
     * @param h height of image
     */
    void setInnerImageSize(int w, int h);

    /**
     * @brief setInnerValue
     * @param hasInnerValue
     */
    void setInnerValue(bool hasInnerValue);

    /**
     * @brief Set InnerFont name for Value inside the progress bar
     * @param fontName
     */
    void setInnerFont(QString fontName);

    /**
     * @brief Set InnerFont Size
     * @param fontSize
     */
    void setInnerFontSize(int fontSize);

    /**
     * @brief Draw PixMap from resource
     * @param p Painter
     * @param imagePath the path to image which is added to resource
     */
    void drawPixMap(QPainter &p, QString imagePath);

    /**
     * @brief set InnerImage Path
     * @param path the path to the image
     */
    void setInnerImagePath(QString path);

    /**
     * @brief Set InnerBackground Color
     * @param color
     */
    void setInnerBackgroundColor(QString color);

    void resizeEvent(int w, int h);

    void setRestProgressColor(QString color);
private:
    /**
     * @brief Draw InnerBackground
     * @param p Painter
     */
    void drawInnerBackground(QPainter &p);

    qreal m_value = 60.; /// progress 0.0 to 100
    qreal m_maxValue = 100.;
    int m_width = 200;
    int m_height = 200;

    int m_progressWidth = 10;

    bool m_progressRounded = true;
    QString m_progressColor = "#30b7e0";
    QString m_restProgressColor = "#d7d7d7";
    QString m_fontFamily = "Montserrat";
    int m_fontSize = 20;
    QString m_suffix = "%";
    bool m_enableShadow = true;

    bool m_hasInnerValue = true;
    bool m_hasInnerImage = false;
    QString m_innerImage = ":/icon/icons/checked.png";
    int m_innerImageWidth = 100;
    int m_innerImageHeight = 100;
    QString m_innerTextColor = "#30b7e0";

    QString m_innerBackgroundColor = "#30b7e0";

};

#endif // CIRCULAR_PROGRESSBAR_H
