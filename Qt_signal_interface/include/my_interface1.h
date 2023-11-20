#pragma once

#ifndef MY_INTERFACE1_H
#define MY_INTERFACE1_H

///
/// How to create a signal interface
/// https://stackoverflow.com/questions/17943496/declare-abstract-signal-in-interface-class
///
class MyInterface1
{
    signals:
        virtual void event1()=0;
};

Q_DECLARE_INTERFACE(MyInterface1, "MyInterface1") // define this out of namespace scope

#endif // MY_INTERFACE1_H
