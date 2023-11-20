#include "myimpl.h"

MyImpl::MyImpl(QObject *parent)
    : QObject(parent)
{}

MyImpl::~MyImpl()
{}

void MyImpl::doWork()
{
    emit event1();
    emit event2();
}
