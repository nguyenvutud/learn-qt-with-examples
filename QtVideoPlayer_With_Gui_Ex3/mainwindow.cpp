#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);

    player->setVideoOutput(vw);
    //video widget will be set at the central of window from
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::durationChanged, bar, &QProgressBar::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, bar, &QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file","~/Videos", "Video file (*.avi, *.mpg, *.mp4)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped..");

}
