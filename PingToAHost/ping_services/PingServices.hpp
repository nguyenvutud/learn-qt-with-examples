#include <QtCore>
#include <QProcess>
#include <QDebug>

#ifndef PINGSERVICES_HPP
#define PINGSERVICES_HPP
class PingServices: public QObject {
    Q_OBJECT
public:
    PingServices(QObject *parent = 0);
    ~PingServices();

    void Stop();

    bool simplePing(QString ip);
public slots:
    void OnPing();
    void OnPingEnded(int, QProcess::ExitStatus);
//signals:
//    void finished(int, QProcess::ExitStatus);
private:
    QProcess mPingProcess;

    QString ip;

};

#endif // PINGSERVICES_HPP

