#include <iostream>
#include "TVectorItem.h"

template <class T> TVectorItem<T>::TVectorItem(std::shared_ptr<Rhombus>& rhomb)
{   
    this->rhomb = rhomb;
    this->next = nullptr;
}

template <class B> std::ostream& operator<<(std::ostream& os, TVectorItem<B> &obj)
{
    os << obj.rhomb << " ";
    return os;
}

template <class T> TVectorItem<T>::~TVectorItem()
{
    std::cout << "TVectorItem deleted" << std::endl;
}