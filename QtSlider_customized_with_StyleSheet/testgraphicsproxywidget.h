#ifndef TESTGRAPHICSPROXYWIDGET_H
#define TESTGRAPHICSPROXYWIDGET_H

#include <QtWidgets/QWidget>



namespace Ui {
class TestGraphicsProxyWidget;
}

class TestGraphicsProxyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestGraphicsProxyWidget(QWidget *parent = nullptr);
    ~TestGraphicsProxyWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TestGraphicsProxyWidget *ui;
};

#endif // TESTGRAPHICSPROXYWIDGET_H
