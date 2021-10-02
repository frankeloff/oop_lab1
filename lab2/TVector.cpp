#include <iostream>
#include "TVector.h"

/*----init----*/
TVector::TVector()
{
    size = 0;
    std::cout << "TVector created" << std::endl;
}

/*----bool----*/

bool TVector::empty()
{
    return size == 0?1:0;
}

/*----TVectorItem*----*/

TVectorItem* TVector::front()
{
    TVectorItem* front = node->first;
    while(front->next != nullptr)
    {
        front = front->next;
    }
    return front;
}

TVectorItem* TVector::back()
{
    return node->first;
}

/*----void----*/

void TVector::clear()
{
    TVectorItem* del = node->first;
    TVectorItem* prev_del;
    if(size == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        while(del->next != nullptr)
        {
            prev_del = del;
            del = del->next;
            delete prev_del;
        }
        delete del;
        size = 0;
        std::cout << "TVector deleted" << std::endl;
    } 
}

void TVector::push_back(Rhombus &&rhomb)
{
    TVectorItem* value = new TVectorItem(rhomb);
    if(size == 0)
    {
        node = value;
        value->first = value;
        node->next = nullptr;
        node->first = value;
        size++;
    }
    else
    {
    value->next = node->first;
    node->first = value;
    value->first = node->first;
    size++;
    }
}

void TVector::push_front(Rhombus &&rhomb)
{
    TVectorItem* value = new TVectorItem(rhomb);
    if(size == 0)
    {
        node = value;
        value->first = value;
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

void TVector::pop_front()
{
    if(size == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        if(size == 1)
        {
            size--;
            TVectorItem* del = node->first;
            delete del;
        }
        else
        {
            TVectorItem* del = node->first;
            TVectorItem* save;
            while(del->next != nullptr)
            {
                save = del;
                del = del->next;
            }
            size--;
            save->next = nullptr;
            delete del;
        }
    }
}

void TVector::pop_back()
{
    if(size == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else if(size == 1)
    {
        size--;
        delete node->first;
    }
    else
    {
    TVectorItem* del = node->first;
    node->first = del->next;
    size--;
    delete del;
    }
}

void TVector::insert(Rhombus &&rhomb, int pos) //correct pos > 0!
{
    if(pos > size + 1 || pos < 1)
    {
        std::cout << "Invalid insert" << std::endl;
    }
    else
    {
        TVectorItem* ins = new TVectorItem(rhomb);
        TVectorItem* prev_ins;
        TVectorItem* next_ins = node->first;
        size++;
        if(pos == 1)
        {
            ins->next = node->first;
            node->first = ins;
            ins->first = node->first;
        }
        else if(pos > size)
        {
            while(next_ins->next != nullptr)
            {
                next_ins = next_ins->next;
            }
            next_ins->next = ins;
            ins->next = nullptr;
            ins->first = node->first;
        }
        else
        {
            for(int i = 0; i < pos - 1; ++i)
                {
                    prev_ins = next_ins;
                    next_ins = next_ins->next;
                }
            prev_ins->next = ins;
            ins->next = next_ins;
            ins->first = node->first;      
        }
    }  
}

void TVector::erase(int pos)
{
    if(pos < 1 || pos > size)
    {
        std::cout << "Invalid erase!" << std::endl;
    }
    else
    {
        TVectorItem* del;
        TVectorItem* prev_del;
        TVectorItem* next_del = node->first;;
        size--;
        if(pos == 1)
        {
            del = node->first;
            next_del = next_del->next;
            node->first = next_del;
            next_del->first = node->first;
            delete del;
        }
        else
        {
            for(int i = 1; i < pos; ++i)
            {
                prev_del = next_del;
                next_del = next_del->next;
            }
            del = next_del;
            next_del = next_del->next;
            prev_del->next = next_del;
            delete del;
        }
    }
}

/*----destructor---*/

TVector::~TVector()
{
    TVectorItem* del = node->first;
    TVectorItem* prev_del;
    if(size == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        while(del->next != nullptr)
        {
            prev_del = del;
            del = del->next;
            delete prev_del;
        }
        delete del;
        size = 0;
        std::cout << "TVector deleted" << std::endl;
    }
}

/*----operator---*/

std::ostream& operator<<(std::ostream& os, TVector& obj)
{
    if(obj.size == 0)
    {
        os << "TList is empty" << std::endl;
    }
    else
    {
    os << "Print rhombus" << std::endl;
    TVectorItem* print = obj.node->first;
    while(print->next != nullptr)
    {
        os << print->rhomb << " " << "," << " ";
        print = print->next;
    }
    os << print->rhomb;
    os << std::endl;
    }
    return os;
}

