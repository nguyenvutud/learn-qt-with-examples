#ifndef LISTSS_H
#define LISTSS_H
#include <QObject>
class ListSS : public QObject
{
    Q_OBJECT
signals:
    /// @brief Emitted when an item is added to the list.
    void itemAdded();

    /// @brief Emitted when the item list is cleared
    void cleared();

public slots:
    /// @brief Clears the list.
    virtual void clear() = 0;

};

#endif // LISTSS_H
