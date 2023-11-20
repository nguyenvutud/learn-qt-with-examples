#include "player_controls.h"
#include "ui_player_controls.h"

PlayerControls::PlayerControls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerControls)
{
    ui->setupUi(this);
    ui->btnPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    ui->btnStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    ui->btnForward->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    ui->btnBackward->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    ui->btnMute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->sliderVolume->setRange(0, 100);

    ui->cmbRate->addItem("0.5x", QVariant(0.5));
    ui->cmbRate->addItem("1.0x", QVariant(1.0));
    ui->cmbRate->addItem("2.0x", QVariant(2.0));
    ui->cmbRate->addItem("3.0x", QVariant(3.0));
    ui->cmbRate->addItem("4.0x", QVariant(4.0));
    ui->cmbRate->setCurrentIndex(1);

    connect(ui->btnStop, &QPushButton::clicked, this, &PlayerControls::stop);
    connect(ui->btnForward, &QPushButton::clicked, this, &PlayerControls::next);
    connect(ui->btnBackward, &QPushButton::clicked, this, &PlayerControls::previous);
    //connect(ui->sliderVolume, &QSlider::valueChanged, this, &PlayerControls::onValumeSlider)
    connect(ui->cmbRate, QOverload<int>::of(&QComboBox::activated), this, &PlayerControls::updateRate);

}

PlayerControls::~PlayerControls()
{
  delete ui;
}

QMediaPlayer::State PlayerControls::state() const
{
  return m_playerState;
}


bool PlayerControls::isMuted() const
{
  return m_playerMuted;
}

void PlayerControls::setState(QMediaPlayer::State state)
{
  if(state != m_playerState){
      m_playerState = state;

      switch(state){
          case QMediaPlayer::StoppedState:
              ui->btnStop->setEnabled(false);
              ui->btnPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
              break;
          case QMediaPlayer::PlayingState:
              ui->btnStop->setEnabled(true);
              ui->btnPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
              break;
          case QMediaPlayer::PausedState:
              ui->btnStop->setEnabled(true);
              ui->btnPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
              break;
      }
  }
}


int PlayerControls::volume() const
{
  qreal linearVolume = QAudio::convertVolume(ui->sliderVolume->value() / qreal(100),
                                             QAudio::LogarithmicVolumeScale,
                                             QAudio::LinearVolumeScale);
  return qRound(linearVolume * 100);
}


void PlayerControls::setVolume(int volume)
{
  qreal logarithmicVolume = QAudio::convertVolume(volume / qreal(100),
                                                  QAudio::LinearVolumeScale,
                                                  QAudio::LogarithmicVolumeScale);
  ui->sliderVolume->setValue(qRound(logarithmicVolume * 100));
}

void PlayerControls::setMuted(bool muted)
{
  if(muted != m_playerMuted) {
      m_playerMuted = muted;
      ui->btnMute->setIcon(style()->standardIcon(muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
  }
}

qreal PlayerControls::playbackRate() const
{
  return ui->cmbRate->itemData(ui->cmbRate->currentIndex()).toDouble();
}

void PlayerControls::setPlaybackRate(float rate)
{
  for (int i = 0; i < ui->cmbRate->count(); ++i) {
      if (qFuzzyCompare(rate, float(ui->cmbRate->itemData(i).toDouble()))) {
          ui->cmbRate->setCurrentIndex(i);
          return;
      }
  }

  ui->cmbRate->addItem(QString("%1x").arg(rate), QVariant(rate));
  ui->cmbRate->setCurrentIndex(ui->cmbRate->count() - 1);
}

void PlayerControls::updateRate()
{
  emit changeRate(playbackRate());
}


void PlayerControls::on_btnPlay_clicked()
{
  switch (m_playerState) {
  case QMediaPlayer::StoppedState:
  case QMediaPlayer::PausedState:
      emit play();
      break;
  case QMediaPlayer::PlayingState:
      emit pause();
      break;
  }
}

void PlayerControls::on_btnMute_clicked()
{
  emit changeMuting(!m_playerMuted);
}

void PlayerControls::on_sliderVolume_valueChanged(int value)
{
  emit changeVolume(volume());
}

