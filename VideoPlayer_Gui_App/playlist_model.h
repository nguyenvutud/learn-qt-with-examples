#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractItemModel>
#include <QScopedPointer>
QT_BEGIN_NAMESPACE
class QMediaPlaylist;
QT_END_NAMESPACE

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class PlayListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum column
    {
        Title = 0,
        ColumnCount
    };

    explicit PlayListModel(QObject *parent = nullptr);
    ~PlayListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QMediaPlaylist *playlist() const;

    void setPlaylist(QMediaPlaylist *playlist);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;
private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);

private:
    QScopedPointer<QMediaPlaylist> m_playlist;
    QMap<QModelIndex, QVariant> m_data;


};

#endif // PLAYLISTMODEL_H
