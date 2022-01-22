#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "rhombus.h"
#include <memory>

template <class T> class TVectorItem
{
public:
    TVectorItem(std::shared_ptr<Rhombus>& rhomb);
    template <class B> friend std::ostream& operator<<(std::ostream& os, TVectorItem<B> &obj);
    ~TVectorItem();
    std::shared_ptr<T> rhomb;
    std::shared_ptr<TVectorItem<T>> next;
};
#include "TVectorItem.inl"
#endif //TVECTORITEM_H