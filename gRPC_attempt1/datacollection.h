#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#include <QtWidgets/QMainWindow>

namespace Ui {
class DataCollection;
}

class DataCollection : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataCollection(QWidget *parent = nullptr);
    ~DataCollection();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DataCollection *ui;

};

#endif // DATACOLLECTION_H
