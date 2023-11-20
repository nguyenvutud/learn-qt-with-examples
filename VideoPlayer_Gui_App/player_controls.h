#ifndef PLAYER_CONTROLS_H
#define PLAYER_CONTROLS_H

#include <QtWidgets/QWidget>
#include <QMediaPlayer>

namespace Ui {
class PlayerControls;
}

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerControls(QWidget *parent = nullptr);
    ~PlayerControls();

    QMediaPlayer::State state() const;
    int volume() const;
    bool isMuted() const;
    qreal playbackRate() const;
public slots:
    void setState(QMediaPlayer::State state);
    void setVolume(int volume);
    void setMuted(bool muted);
    void setPlaybackRate(float rate);
signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeVolume(int volume);
    void changeMuting(bool muting);
    void changeRate(qreal rate);
private slots:
//    void playClicked();
//    void muteClicked();
    void updateRate();
//    void onVolumeSliderValueChanged();

    void on_btnPlay_clicked();

    void on_btnMute_clicked();

    void on_sliderVolume_valueChanged(int value);

private:
    Ui::PlayerControls *ui;

    QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState;
    bool m_playerMuted = false;
};

#endif // PLAYER_CONTROLS_H
