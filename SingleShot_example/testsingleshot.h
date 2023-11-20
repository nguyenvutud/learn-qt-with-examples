#ifndef TESTSINGLESHOT_H
#define TESTSINGLESHOT_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QTimer>

class TestSingleShot : public QObject
{
    Q_OBJECT
public:
    explicit TestSingleShot(QObject *parent = nullptr);

    void startHello();
signals:
private slots:

    void hello();

};

#endif // TESTSINGLESHOT_H
