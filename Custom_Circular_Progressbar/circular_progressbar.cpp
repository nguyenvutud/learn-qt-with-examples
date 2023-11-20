#include <QPainter>
#include <QDebug>
#include <QStaticText>

#include "circular_progressbar.h"

CircularProgressBar::CircularProgressBar(QWidget *parent) :
    QWidget(parent)
{

    setMinimumSize(200, 200);

}

CircularProgressBar::~CircularProgressBar()
{

}

void CircularProgressBar::paintEvent(QPaintEvent *e)
{

    int width = m_width - m_progressWidth;
    int height = m_height - m_progressWidth;
    int margin = m_progressWidth / 2.0;
    qreal value = m_value * 360 / m_maxValue;

    qreal rValue = 360 - value;

    //Create Rectangle
    QRectF rect(0, 0, m_width, m_height);

    //Create painter
    QPainter painter(this);


    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont(m_fontFamily, m_fontSize));


    painter.setPen(Qt::NoPen);
    painter.drawRect(rect);

    //Create pen
    QPen pen;

    // create Arg for the rest of circle
    pen.setColor(QColor(m_restProgressColor));
    pen.setWidth(m_progressWidth);
    painter.setPen(pen);
    painter.drawArc(margin, margin, width, height, 90 * 16, rValue * 16);

    if (m_progressRounded)
        pen.setCapStyle(Qt::RoundCap);
    pen.setColor(QColor(m_progressColor)); //"#30b7e0"

    // Create Arg/ circular progress
    painter.setPen(pen);
    painter.drawArc(margin, margin, width, height, 90 * 16, -value * 16);

    //Create Text
    if (m_hasInnerValue){
        pen.setColor(QColor(m_innerTextColor));
        painter.setPen(pen);
        QString text = QString::number(m_value);


        painter.drawText(rect, Qt::AlignCenter, text);

        QRectF rectText = painter.boundingRect(rect, text);

        // setup color and font size for the suffix.
        // the font size of suffix is 1/3 of main text font size
        painter.setFont(QFont(m_fontFamily, m_fontSize/3.0));
        rectText.setX(rect.center().x() + rectText.width()/2.0);
        rectText.setY(rect.center().y());
        rectText.setWidth(30);
        rectText.setHeight(30);

        painter.drawText(rectText, m_suffix);

        /* Another idea to setup the font for text is to use html text format
         * QStaticText text;
        text.setTextWidth(rect.width());
        text.setText(QString("<b>%1</b>%").arg(m_value));
        painter.drawStaticText(QPoint(rect.bottomRight().x()/2 - text.textWidth()/2,
                                      rect.bottomRight().y()/2 - text.textWidth()/2), text);
        */
    }

    // draw a pixmap
    if (m_hasInnerImage)
    {
        drawPixMap(painter, m_innerImage);
    }

    //drawInnerBackground(painter);

    QWidget::paintEvent(e);

    qInfo() << "Paintevent called!";
}

void CircularProgressBar::resizeEvent(int w, int h)
{
    m_width = w;
    m_height = h;
//    this->resize(w, h);
    this->setMinimumSize(w, h);
    update();
}

void CircularProgressBar::setRestProgressColor(QString color)
{
    if(!color.isEmpty() && (color != m_restProgressColor))
    {
        m_restProgressColor = color;
        update();
    }
}

void CircularProgressBar::setProgressWidth(int width)
{
    if(width != m_progressWidth)
    {
        if(width < 0)
            m_progressWidth = 0;
        else if(width > m_maxValue)
            m_progressWidth = m_maxValue;
        else
            m_progressWidth = width;
        update();
    }
}

void CircularProgressBar::setProgressColor(QString color)
{
    if(!color.isEmpty() && (color != m_progressColor))
    {
        m_progressColor = color;
        update();
    }
}

void CircularProgressBar::setInnerTextColor(QString color)
{
    if(!color.isEmpty() && (color != m_innerTextColor))
    {
        m_innerTextColor = color;
        update();
    }
}

void CircularProgressBar::setInnerImage(bool hasImage)
{
    if(hasImage != m_hasInnerImage)
    {
        m_hasInnerImage = hasImage;
        update();
    }
}

void CircularProgressBar::setInnerImageSize(int w, int h)
{
    m_innerImageWidth = w;
    if(w > m_width)
        m_innerImageWidth = m_width;
    m_innerImageHeight = h;
    if(h > m_height)
        m_innerImageHeight = m_height;
    update();
}

void CircularProgressBar::setInnerValue(bool hasInnerValue)
{
    if (hasInnerValue != m_hasInnerValue)
    {
        m_hasInnerValue = hasInnerValue;
        update();
    }
}

void CircularProgressBar::setInnerFont(QString fontName)
{
    if(fontName != m_fontFamily)
    {
        m_fontFamily = fontName;
        update();
    }
}

void CircularProgressBar::setInnerFontSize(int fontSize)
{
    if(fontSize != m_fontSize){
        m_fontSize = fontSize;
        update();
    }
}


void CircularProgressBar::drawPixMap(QPainter &p, QString imagePath)
{
//    QPixmap pixmap(imagePath);
    QRect rect(0, 0, m_width, m_height);
    QRect rectImage(0, 0, m_width, m_height);
    QPoint point = (rect.bottomRight() / 2);
//    p.drawPixmap(point.x(), point.y(),
//                 m_innerImageWidth, m_innerImageHeight, pixmap);

    //Your's calculation area
    QRect topPortion = QRect(QPoint(0, 0), QSize(width() , (height() / 4) * 3 - 2*m_progressWidth));

//    QPixmap pixmap = QPixmap(1024, 768); //Random image
    QPixmap pixmap(imagePath);
    //pixmap.fill(Qt::red); //Random color

    qInfo() << "Pixmap size:" << pixmap.size();

    //Scaled size that will be used to set draw aera to QPainter, with aspect ratio preserved
    QSize size = pixmap.size().scaled(topPortion.size(), Qt::KeepAspectRatio);

    qInfo() << "Pixmap resize:" << size;

    //Note: QPainter::SmoothPixmapTransform works perfectly
    p.setRenderHint(QPainter::SmoothPixmapTransform);

    //Draw the pixmap inside the scaled area, with aspect ratio preserved
    p.drawPixmap(width()/2.0 - size.width()/2.0, height()/2 - size.height()/2.0,
                 size.width(), size.height(), pixmap);

}

void CircularProgressBar::setInnerImagePath(QString path)
{
    if(!path.isEmpty() && (path != m_innerImage))
    {
        m_innerImage = path;
        update();
    }
}

void CircularProgressBar::setInnerBackgroundColor(QString color)
{
    if(!color.isEmpty() && (color != m_innerBackgroundColor))
    {
        m_innerBackgroundColor = color;
        update();
    }
}

void CircularProgressBar::drawInnerBackground(QPainter &p)
{
    if(!m_innerBackgroundColor.isEmpty())
    {
        QBrush brush;
        brush.setColor(QColor(m_innerBackgroundColor));
        p.setBrush(brush);
        QRectF innerRect(m_progressWidth/2, m_progressWidth/2,
                        m_width - m_progressWidth, m_height - m_progressWidth);
        p.drawEllipse(innerRect);
    }
}

