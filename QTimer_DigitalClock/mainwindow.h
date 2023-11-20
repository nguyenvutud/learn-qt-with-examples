#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif
#include <QTimer>
#include "mytimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    MyTimer myTimer;
signals:
    void stopCounter();

public slots:
    void myFunction();
    void onNewValues(int hours, int mins, int secs);

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
};
#endif // MAINWINDOW_H
