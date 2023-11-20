#ifndef QTINTERFACES_H
#define QTINTERFACES_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include "duck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtInterfaces; }
QT_END_NAMESPACE

class QtInterfaces : public QMainWindow
{
    Q_OBJECT

public:
    QtInterfaces(QWidget *parent = nullptr);
    ~QtInterfaces();
public slots:

    void onNewSound(QString sound);

private:
    Ui::QtInterfaces *ui;
    Duck* duck;
};
#endif // QTINTERFACES_H
