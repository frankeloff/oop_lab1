#include <iostream>
#include "rhombus.h"

class TListItem
{
public:
    TListItem(Rhombus &rhomb);
    friend std::ostream& operator<<(std::ostream& os, TListItem& obj);
    ~TListItem();
    Rhombus rhomb;
    TListItem* next;
    TListItem* first;
};