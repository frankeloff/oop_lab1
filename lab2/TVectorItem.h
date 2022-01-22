#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "rhombus.h"

class TVectorItem
{
public:
    TVectorItem(const Rhombus &rhomb);
    friend std::ostream& operator<<(std::ostream& os, TVectorItem& obj);
    ~TVectorItem();
    Rhombus rhomb;
    TVectorItem* next;
};

#endif //TVECTORITEM_H