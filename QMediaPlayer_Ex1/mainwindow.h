#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include <QDebug>
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

private:
    Ui::MainWindow *ui;

    QMediaPlayer *player;
};
#endif // MAINWINDOW_H
