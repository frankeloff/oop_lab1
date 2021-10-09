#include <iostream>
#include "TVector.h"
#include <memory>

/*----init----*/
TVector::TVector()
{
    node = nullptr;
    size = 0;
    std::cout << "TVector created" << std::endl;
}

/*----bool----*/

bool TVector::empty()
{
    return size == 0;
}

/*----TVectorItem*----*/

std::shared_ptr<TVectorItem> TVector::back()
{
    std::shared_ptr<TVectorItem> front = node->first;
    while(front->next != nullptr)
    {
        front = front->next;
    }
    return front;
}

std::shared_ptr<TVectorItem> TVector::front()
{
    return node->first;
}

/*----void----*/

void TVector::clear()
{
    // std::shared_ptr<TVectorItem> del = node->first;
    // std::shared_ptr<TVectorItem> prev_del;
    // if(size == 0)
    // {
    //     std::cout << "List is empty" << std::endl;
    // }
    // else
    // {
    //     while(del->next != nullptr)
    //     {
    //         prev_del = del;
    //         del = del->next;
    //     }
    //     size = 0;
    //     std::cout << "TVector deleted" << std::endl;
    // } 
    size = 0;
    std::cout << "TVector deleted" << std::endl;
}

void TVector::push_front(std::shared_ptr<Rhombus> &&rhomb)
{
    std::shared_ptr<TVectorItem> value(new TVectorItem(rhomb));
    if(size == 0)
    {
        node = value;
        node->next = nullptr;
        node->first = value;
        size++;
    }
    else
    {
        value->next = node->first;
        value->first = value;
        std::shared_ptr<TVectorItem> nex = value->next;
        while(nex->next != nullptr)
        {
            nex->first = value;
            nex = nex->next;
        }
        nex->first = value;
        size++;
    }
}

void TVector::push_back(std::shared_ptr<Rhombus> &&rhomb)
{
    std::shared_ptr<TVectorItem> value(new TVectorItem(rhomb));
    if(size == 0)
    {
        node = value;
        node->next = nullptr;
        node->first = value;
        size++;
    }
    else 
    {  
        std::shared_ptr<TVectorItem> end = node->first;
        while(end->next != nullptr)
        {
            end = end->next;
        }
        end->next = value;
        value->first = end->first;
        value->next = nullptr;
        size++;
    }
}

void TVector::pop_back()
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
            std::shared_ptr<TVectorItem> del = node->first;
        }
        else
        {
            std::shared_ptr<TVectorItem> del = node->first;
            std::shared_ptr<TVectorItem> save;
            while(del->next != nullptr)
            {
                save = del;
                del = del->next;
            }
            size--;
            save->next = nullptr;
        }
    }
}

void TVector::pop_front()
{
    if(size == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else if(size == 1)
    {
        size--;
    }
    else
    {
    std::shared_ptr<TVectorItem> del = node->first;
    std::shared_ptr<TVectorItem> save = node->first;
    save = save->next;
    std::shared_ptr<TVectorItem> fir = save;
    while(save->next != nullptr)
    {
        save->first = fir;
        save = save->next;
    }
    save->first = fir;
    size--;
    }
}

void TVector::insert(std::shared_ptr<Rhombus> &&rhomb, int pos) //correct pos > 0!
{
    if(pos > size + 1 || pos < 1)
    {
        std::cout << "Invalid insert" << std::endl;
    }
    else
    {
        std::shared_ptr<TVectorItem> ins (new TVectorItem(rhomb));
        std::shared_ptr<TVectorItem> prev_ins;
        std::shared_ptr<TVectorItem> next_ins = node->first;
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
        std::shared_ptr<TVectorItem> del;
        std::shared_ptr<TVectorItem> prev_del;
        std::shared_ptr<TVectorItem> next_del = node->first;;
        size--;
        if(pos == 1)
        {
            del = node->first;
            next_del = next_del->next;
            node->first = next_del;
            next_del->first = node->first;
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
        }
    }
}

/*----destructor---*/

TVector::~TVector()
{
    std::cout << "TVector deleted" << std::endl;
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
    std::shared_ptr<TVectorItem> print = obj.node->first;
    while(print->next != nullptr)
    {
        os << *print->rhomb << " " << "," << " ";
        print = print->next;
    }
    os << *print->rhomb;
    os << std::endl;
    }
    return os;
}

