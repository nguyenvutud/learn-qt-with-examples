#ifndef LIST_H
#define LIST_H
#include <QObject>
#include <QList>

#include "ListSS.h"


/// @brief Because template class is not supported by QObject
/// therefore we have to create a base class ListSS containing 'signals functions
template <typename T>
class List : public ListSS {

private:
    QList<T> mItems;

    T mPlaceHolder;

public:

    List(){};
    ~List(){};
    void appendItem(T item){
        mItems.append(item);
        mPlaceHolder = item;
        emit itemAdded();
    }

    T getPlaceHolder(){
        return mPlaceHolder;
    }

    void clear() override{
        mItems.clear();
        emit cleared();
    }
};
#endif // LIST_H
