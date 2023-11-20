#include <QMediaService>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTime>
#include <QFormLayout>
#include <QMessageBox>

#include "player.h"
#include "ui_player.h"

#include "player_controls.h"
#include "playlist_model.h"
#include "video_widget.h"

Player::Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
//! [create-objs]
    m_player = new QMediaPlayer(this);
    m_player->setAudioRole(QAudio::VideoRole);
    qInfo() << "Supported audio roles:";
    for (QAudio::Role role: m_player->supportedAudioRoles())
        qInfo() << "  " << role;
    //owned by PlaylistModel
    m_playlist = new QMediaPlaylist();
    m_player->setPlaylist(m_playlist);
//! [create-objs]

    connect(m_player, &QMediaPlayer::durationChanged, this, &Player::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Player::positionChanged);

    connect(m_player, &QMediaPlayer::videoAvailableChanged, this, &Player::videoAvailableChanged);

    //color button
    ui->btnColor->setEnabled(false);
    connect(ui->btnColor, &QPushButton::clicked, this, &Player::showColorDialog);

    m_videoWidget = new VideoWidget(this);
    m_player->setVideoOutput(m_videoWidget);

    m_playlistModel = new PlayListModel(this);
    m_playlistModel->setPlaylist(m_playlist);

    m_playlistView = new QListView(this);
    m_playlistView->setModel(m_playlistModel);
    m_playlistView->setCurrentIndex(m_playlistModel->index(m_playlist->currentIndex(), 0));

    ui->displayLayout->addWidget(m_videoWidget, 2);
    ui->displayLayout->addWidget(m_playlistView);

    //player-controls
    PlayerControls *controls = new PlayerControls(this);
    controls->setState(m_player->state());
    controls->setVolume(m_player->volume());
    controls->setMuted(controls->isMuted());
    //Connection
    connect(controls, &PlayerControls::play, m_player, &QMediaPlayer::play);
    connect(controls, &PlayerControls::stop, m_player, &QMediaPlayer::stop);
    connect(controls, &PlayerControls::pause, m_player, &QMediaPlayer::pause);
    connect(controls, &PlayerControls::next, m_playlist, &QMediaPlaylist::next);
    //connect(controls, &PlayerControls::previous, m_playlist, &QMediaPlaylist::previous);
    connect(controls, &PlayerControls::previous, this, &Player::previousClicked);
    connect(controls, &PlayerControls::changeVolume, m_player, &QMediaPlayer::setVolume);
    connect(controls, &PlayerControls::changeMuting, m_player, &QMediaPlayer::setMuted);

    connect(controls, &PlayerControls::stop, m_videoWidget, QOverload<>::of(&QVideoWidget::update));
    connect(controls, &PlayerControls::changeRate, m_player, &QMediaPlayer::setPlaybackRate);

    connect(m_player, &QMediaPlayer::stateChanged, controls, &PlayerControls::setState);
    connect(m_player, &QMediaPlayer::volumeChanged, controls, &PlayerControls::setVolume);
    connect(m_player, &QMediaPlayer::mutedChanged, controls, &PlayerControls::setMuted);

    //fullscreen button
    ui->btnFullScreen->setCheckable(true);

    ui->btnColor->setEnabled(false);

    //add to controlLayout
    ui->controlLayout->addWidget(controls);

    connect(ui->btnOpen, &QPushButton::clicked, this, &Player::open);

    if (!isPlayerAvailable()) {
        QMessageBox::warning(this, "Service not available",
                             "Please double check Media service plugins!");
        controls->setEnabled(false);
        m_playlistView->setEnabled(false);
        ui->btnOpen->setEnabled(false);
        ui->btnColor->setEnabled(false);
        ui->btnFullScreen->setEnabled(false);
    }


}

Player::~Player()
{
    delete ui;
}

bool Player::isPlayerAvailable() const
{
    return m_player->isAvailable();
}

static bool isPlayList(const QUrl &url) //check for ".m3u" playlists.
{
    if(!url.isLocalFile())
        return false;
    const QFileInfo fileInfo(url.toLocalFile());
    return fileInfo.exists() && !fileInfo.suffix().compare(QLatin1String("m3u"), Qt::CaseInsensitive);
}
void Player::addToPlayList(const QList<QUrl> &urls)
{
    for (auto &url: urls){
        if (isPlayList(url))
            m_playlist->load(url);
        else
            m_playlist->addMedia(url);
    }
}

void Player::setCustomAudioRole(const QString &role)
{
    m_player->setCustomAudioRole(role);
}

void Player::open()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle("Open Files");
    QStringList supportedMineTypes = m_player->supportedMimeTypes();
    if (!supportedMineTypes.isEmpty()) {
        supportedMineTypes.append("");
        fileDialog.setMimeTypeFilters(supportedMineTypes);
    }
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted){
        addToPlayList(fileDialog.selectedUrls());

        qInfo() << fileDialog.selectedUrls();
    }
}

void Player::durationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    ui->sliderTime->setMaximum(m_duration);

    qInfo() << "Duration changed: " << m_duration;
}

void Player::positionChanged(qint64 progress)
{
    if (!ui->sliderTime->isSliderDown())
        ui->sliderTime->setValue(progress / 1000);
    updateDurationInfo(progress / 1000);
}

void Player::previousClicked()
{
    if (m_playlist->currentIndex() > 0)
        m_playlist->previous();
    else
        m_player->setPosition(0);
}

void Player::playlistPositionChanged(int currentItem)
{
    //clearHistogram();
    m_playlistView->setCurrentIndex(m_playlistModel->index(currentItem, 0));

}

void Player::videoAvailableChanged(bool available)
{
    if (!available){
        disconnect(ui->btnFullScreen, &QPushButton::clicked, m_videoWidget, &QVideoWidget::setFullScreen);
        disconnect(m_videoWidget, &QVideoWidget::fullScreenChanged, ui->btnFullScreen, &QPushButton::setChecked);
        m_videoWidget->setFullScreen(false);
    } else {
        connect(ui->btnFullScreen, &QPushButton::clicked, m_videoWidget, &QVideoWidget::setFullScreen);
        connect(m_videoWidget, &QVideoWidget::fullScreenChanged, ui->btnFullScreen, &QPushButton::setChecked);
        if (ui->btnFullScreen->isChecked())
            m_videoWidget->setFullScreen(true);
    }
    ui->btnColor->setEnabled(available);

}

void Player::showColorDialog()
{
    QSlider *sliderBrightness = new QSlider(Qt::Horizontal);
    sliderBrightness->setRange(-100, 100);
    sliderBrightness->setValue(m_videoWidget->brightness());
    connect(sliderBrightness, &QSlider::sliderMoved, m_videoWidget, &QVideoWidget::setBrightness);
    connect(m_videoWidget, &QVideoWidget::brightnessChanged, sliderBrightness, &QSlider::setValue);

    QSlider *sliderContrast = new QSlider(Qt::Horizontal);
    sliderContrast->setRange(-100, 100);
    sliderContrast->setValue(m_videoWidget->contrast());
    connect(sliderContrast, &QSlider::sliderMoved, m_videoWidget, &QVideoWidget::setContrast);
    connect(m_videoWidget, &QVideoWidget::contrastChanged, sliderContrast, &QSlider::setValue);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Brightness", sliderBrightness);
    layout->addRow("Contrast", sliderContrast);

    QPushButton *button = new QPushButton("Close");
    layout->addRow(button);

    m_colorDialog = new QDialog(this);
    m_colorDialog->setWindowTitle("Color Options");
    m_colorDialog->setLayout(layout);

    connect(button, &QPushButton::clicked, m_colorDialog, &QDialog::close);
    m_colorDialog->show();
}

void Player::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Player::updateDurationInfo(qint64 currentInfo)
{
    QString durationInfo;
    if( currentInfo || m_duration){
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
                          currentInfo % 60, (currentInfo * 1000) % 1000);

        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
                        m_duration % 60, (m_duration * 1000) % 1000);

        QString format = "mm:ss";
        if (m_duration > 3600)
            format = "hh:mm:ss";

        qInfo() << "Total time:" << totalTime.toString();

        durationInfo = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    ui->lblDuration->setText(durationInfo);
}
