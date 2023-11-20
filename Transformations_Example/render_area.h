#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class RenderArea; }
QT_END_NAMESPACE

/**
 * @brief The RenderArea class
 * https://doc.qt.io/qt-5/qtwidgets-painting-transformations-example.html
 */
class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

private:
    Ui::RenderArea *ui;
};
#endif // RENDERAREA_H
