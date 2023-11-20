#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>

#else
#include <QtGui/QMainWindow>
#endif

#include "../QProcess_system_command/qprocess_libs/system_command_process.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void testCommand();
private slots:
    void on_btnKillProcess_clicked();

private:
    Ui::MainWindow *ui;

    SystemCommandProcess *m_process;
};
#endif // MAINWINDOW_H
