#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

namespace Ui {
class CustomGraphicsItem;
}

class CustomGraphicsItem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomGraphicsItem(QWidget *parent = nullptr);
    ~CustomGraphicsItem();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CustomGraphicsItem *ui;
};

#endif // CUSTOMGRAPHICSITEM_H
