#include <QFileInfo>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_btnStart_clicked()
{
    //Load the file
    player->setMedia(QUrl::fromLocalFile(QFileInfo("./mp3files/test.mp3").absoluteFilePath()));
    player->play();
    qInfo() << player->errorString();
}

void MainWindow::on_btnStop_clicked()
{
    player->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}
