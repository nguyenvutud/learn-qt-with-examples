#ifndef SUPERBACKGROUNDPAINTER_H
#define SUPERBACKGROUNDPAINTER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class SuperBackgroundPainter : public QObject
{
    Q_OBJECT
public:
    explicit SuperBackgroundPainter(QObject *parent = nullptr);
    void eventFilter(QObject *watched, QEvent *event);

signals:

};

#endif // SUPERBACKGROUNDPAINTER_H
