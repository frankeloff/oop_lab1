#include <iostream>
#include "rhombus.h"

class TVectorItem
{
public:
    TVectorItem(Rhombus &rhomb);
    friend std::ostream& operator<<(std::ostream& os, TVectorItem& obj);
    ~TVectorItem();
    Rhombus rhomb;
    TVectorItem* next;
    TVectorItem* first;
};