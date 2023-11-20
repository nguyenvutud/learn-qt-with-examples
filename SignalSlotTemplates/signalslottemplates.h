#ifndef SIGNALSLOTTEMPLATES_H
#define SIGNALSLOTTEMPLATES_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include "List.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SignalSlotTemplates; }
QT_END_NAMESPACE

class SignalSlotTemplates : public QMainWindow
{
    Q_OBJECT

public:
    SignalSlotTemplates(QWidget *parent = nullptr);
    ~SignalSlotTemplates();

public slots:
    /// @brief Triggered when the add Item button is clicked
    void onAddItemClick();

    /// @brief Triggered when an item is added to the Item list.
    void onAddedItem();

    /// @brief Triggered when the item list is cleared
    void onCleared();

private:
    Ui::SignalSlotTemplates *ui;

    List<int> mItems;
};
#endif // SIGNALSLOTTEMPLATES_H
