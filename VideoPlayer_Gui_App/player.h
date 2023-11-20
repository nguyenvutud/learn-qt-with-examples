#ifndef PLAYER_H
#define PLAYER_H


#include <QtWidgets/QWidget>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListView>

#include <QAbstractItemView>
#include <QVideoProbe>
#include <QAudioProbe>
#include <QVideoWidget>

class PlayListModel;
class HistogramWidget;

namespace Ui {

class Player;
}

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();
    bool isPlayerAvailable() const;

    void addToPlayList(const QList<QUrl> &urls);
    void setCustomAudioRole(const QString &role);

signals:
    void fullScreenChanged(bool fullScreen);

private slots:
    void open();
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
//    void metaDataChanged();

    /**
     * @brief previousClicked Go to previous track if we are within the first 5 seconds of playback
     * otherwise, seek to the beginning
     */
    void previousClicked();
//    void seek(int seconds);
//    void jump(const QModelIndex &index);
    /**
     * @brief playlistPositionChanged change video/audio in playlist
     */
    void playlistPositionChanged(int);

//    void statusChanged(QMediaPlayer::MediaStatus status);
//    void stateChanged(QMediaPlayer::State state);
//    void bufferingProgress(int progress);

    /**
     * @brief videoAvailableChanged check whether video is available for playing or not
     * @param available is true/false
     */
    void videoAvailableChanged(bool available);

//    void displayErrorMessage();

    void showColorDialog();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::Player *ui;

    void clearHistogram();
    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);

    QMediaPlayer *m_player = nullptr;
    QMediaPlaylist *m_playlist = nullptr;
    QVideoWidget *m_videoWidget = nullptr;

    QDialog *m_colorDialog = nullptr;

    QVideoProbe *m_videoProbe = nullptr;
    QAudioProbe *m_audioProbe = nullptr;

    PlayListModel *m_playlistModel = nullptr;
    QAbstractItemView *m_playlistView = nullptr;
    QString m_trackInfo;
    QString m_statusInfo;
    qint64 m_duration;


};

#endif // PLAYER_H
