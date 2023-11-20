#pragma once
#ifndef MY_INTERFACE2_H
#define MY_INTERFACE2_H
class MyInterface2
{
signals:
    virtual void event2() = 0;
};

Q_DECLARE_INTERFACE(MyInterface2, "MyInterface2") // define this out of namespace scope

#endif // MY_INTERFACE2_H
