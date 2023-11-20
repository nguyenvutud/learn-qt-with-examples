#include "playlist_model.h"

#include <QFileInfo>
#include <QUrl>
#include <QMediaPlaylist>

PlayListModel::PlayListModel(QObject *parent):
    QAbstractItemModel(parent)
{

}

PlayListModel::~PlayListModel()
{

}

int PlayListModel::rowCount(const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid() ? m_playlist->mediaCount() : 0;
}

int PlayListModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? ColumnCount : 0;
}

QModelIndex PlayListModel::index(int row, int column, const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid() && row >=0
            && row < m_playlist->mediaCount()
            && column >= 0 && column < ColumnCount
            ? createIndex(row, column) : QModelIndex();
}

QModelIndex PlayListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = m_data[index];
        if (!value.isValid() && index.column() == Title) {
            QUrl location = m_playlist->media(index.row()).canonicalUrl();
            return QFileInfo(location.path()).fileName();
        }
        return value;

    }
    return QVariant();
}

QMediaPlaylist *PlayListModel::playlist() const
{
    return m_playlist.data();
}

void PlayListModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (m_playlist) {
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeInserted, this, &PlayListModel::beginInsertItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaInserted, this, &PlayListModel::endInsertItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeRemoved, this, &PlayListModel::beginRemoveItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaRemoved, this, &PlayListModel::endRemoveItems);
        disconnect(m_playlist.data(), &QMediaPlaylist::mediaChanged, this, &PlayListModel::changeItems);
    }

    beginResetModel();
    m_playlist.reset(playlist);

    if (m_playlist) {
        connect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeInserted, this, &PlayListModel::beginInsertItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaInserted, this, &PlayListModel::endInsertItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaAboutToBeRemoved, this, &PlayListModel::beginRemoveItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaRemoved, this, &PlayListModel::endRemoveItems);
        connect(m_playlist.data(), &QMediaPlaylist::mediaChanged, this, &PlayListModel::changeItems);

    }
    endResetModel();
}

bool PlayListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    m_data[index] = value;
    emit dataChanged(index, index);
    return true;
}

void PlayListModel::beginInsertItems(int start, int end)
{
    m_data.clear();
    beginInsertRows(QModelIndex(), start, end);
}

void PlayListModel::endInsertItems()
{
    endInsertRows();
}

void PlayListModel::beginRemoveItems(int start, int end)
{
    m_data.clear();
    beginRemoveRows(QModelIndex(), start, end);
}

void PlayListModel::endRemoveItems()
{
    endRemoveRows(); //or endInsertRows()???
}

void PlayListModel::changeItems(int start, int end)
{
    m_data.clear();
    emit dataChanged(index(start, 0), index(end, ColumnCount));
}

