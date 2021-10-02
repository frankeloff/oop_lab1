#include <iostream>
#include "TListItem.h"

TListItem::TListItem(Rhombus &rhomb)
{   
    this->rhomb = rhomb;
    this->first = this->next = nullptr;
}

std::ostream& operator<<(std::ostream& os, TListItem& obj)
{
    os << obj.rhomb << " ";
    return os;
}

TListItem::~TListItem()
{
    std::cout << "TListItem deleted" << std::endl;
}