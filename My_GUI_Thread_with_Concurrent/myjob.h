#ifndef MYJOB_H
#define MYJOB_H

#include <QtCore/qglobal.h>
#include <QDebug>
#include <QThread>

///
/// \brief The MyJob class
/// https://www.youtube.com/watch?v=tvpC8UrPpZ4
///
class MyJob : public QObject
{
    Q_OBJECT
signals:
    void onNumber(QString name, int number);

public slots:
    void stop();
public:
    explicit MyJob(QObject* parent = 0);
    ~MyJob();
    void start(QString name);
private:
    bool mStop;
};

#endif // MYJOB_H
