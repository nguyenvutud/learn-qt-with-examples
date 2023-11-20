#ifndef CAT_H
#define CAT_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QDebug>

//why do we inherit from QObject
class Cat: public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);
    ~Cat();

    QString name() const;
    void setName(const QString &name);

    int age() const;
    void setAge(int age);

private:
    QString m_name;
    int m_age;
};

#endif // CAT_H
