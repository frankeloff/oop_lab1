#include <iostream>
#include "TListItem.h"
#include "rhombus.h"

class TList
{
public:
    TList();
    void push(Rhombus &&rhomb);
    TListItem* pop();
    bool isEmpty(int list);
    friend std::ostream& operator<<(std::ostream& os, TList& obj);
    ~TList();
private:
    int size;
    TListItem *node;
};