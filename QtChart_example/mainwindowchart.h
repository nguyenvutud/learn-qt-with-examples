#ifndef MAINWINDOWCHART_H
#define MAINWINDOWCHART_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowChart; }
QT_END_NAMESPACE

class MainWindowChart : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowChart(QWidget *parent = nullptr);
    ~MainWindowChart();

private:
    Ui::MainWindowChart *ui;
};
#endif // MAINWINDOWCHART_H
