#include <iostream>
#include "TList.h"

TList::TList()
{
    this->node = nullptr;
    size = 0;
    std::cout << "TList created" << std::endl;
}

TList::~TList()
{
    TListItem* del = node->first;
    TListItem* prev_del;
    if(isEmpty(size))
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        while(del->next != nullptr)
        {
            prev_del = del;
            del = del->next;
            free(prev_del);
        }
        free(del);
        std::cout << "TList deleted" << std::endl;
    }
}

bool TList::isEmpty(int size)
{
    if(size == 0)
    {
        return 1;
    }
    return 0;
}

void TList::push(Rhombus &&rhomb)
{
    TListItem* value = new TListItem(rhomb);
    if(size == 0)
    {
        node = value;
        node->next = nullptr;
        node->first = value;
        size++;
    }
    else 
    {  
        node->next = value;
        value->first = node->first;
        node = node->next;
        node->next = nullptr;
        size++;
    }
}

TListItem* TList::pop()
{
    TListItem* del = node->first;
    TListItem* save;
    if(isEmpty(size))
    {
        std::cout << "List is empty" << std::endl;
        return del;
    }
    else
    {
        for(int i = 0; i < size - 1; i++)
        {
            save = del;
            del = del->next;
        }
        save->next = nullptr;
        return del;
    }
}

std::ostream& operator<<(std::ostream& os, TList& obj)
{
    os << "Print rhombus" << std::endl;
    TListItem* print = obj.node->first;
    while(print->next != nullptr)
    {
        os << print->rhomb << " ";
        print = print->next;
    }
    os << print->rhomb;
    os << std::endl;
    return os;
}

