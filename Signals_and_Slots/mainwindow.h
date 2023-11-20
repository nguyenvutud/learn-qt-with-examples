#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    //ex1,2
    void releaseSmoke();

    //ex4: with arguments
    void releaseSmoke_ex4(int param1, int param2);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onClicked();

    //ex2
    void burnLogs();
    void villagersReact();

    //ex3
    static void villagersReact_ex3();

    //ex4
    void burnLogs_ex4();
    void villagersReact_ex4(int param1);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
