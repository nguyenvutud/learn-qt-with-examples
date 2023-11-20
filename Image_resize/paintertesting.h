#ifndef PAINTERTESTING_H
#define PAINTERTESTING_H


#include <QtWidgets/QWidget>


namespace Ui {
class PainterTesting;
}

class PainterTesting : public QWidget
{
    Q_OBJECT

public:
    explicit PainterTesting(QWidget *parent = nullptr);
    ~PainterTesting();
    void paintEvent(QPaintEvent *pe);
    void resizeEvent(QResizeEvent *e);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PainterTesting *ui;
    QPixmap _pixmapBg;

};

#endif // PAINTERTESTING_H
