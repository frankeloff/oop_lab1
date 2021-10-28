#include <iostream>
#include "TVector.h"

/*----init----*/
TVector::TVector()
{
    size = 0;
    std::cout << "TVector created" << std::endl;
}

/*----bool----*/

bool TVector::Empty()
{
    return size == 0?1:0;
}

void TVector::InsertLast(std::shared_ptr<Rhombus> &&rhomb)
{
    std::shared_ptr<TVectorItem> value (new TVectorItem(rhomb));
    if(size == 0)
    {
        this->first = value;
        this->first->next = nullptr;
        this->first = value;
        size++;
    }
    else 
    {  
        std::shared_ptr<TVectorItem> end = this->first;
        while(end->next != nullptr)
        {
            end = end->next;
        }
        end->next = value;
        value->next = nullptr;
        size++;
    }
}

void TVector::Resize(const size_t new_size)
{
    if(size == new_size || new_size  < 1)
    {
        return;
    }
    else if(new_size > size)
    {
        size_t iter = new_size - size;
        for(int i = 0; i < iter; i++)
        {
            InsertLast(std::shared_ptr<Rhombus>(new Rhombus()));
        }
    }
    else{
        size_t iter = new_size;
        std::shared_ptr<TVectorItem> end = this->first;
        for(int i = 0; i < iter; i++)
        {
            end = end->next;
        }
        end->next = nullptr;
    }
    size = new_size;
}

void TVector::RemoveLast()
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
            std::shared_ptr<TVectorItem> del = this->first;
        }
        else
        {
            std::shared_ptr<TVectorItem> del = this->first;
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

void TVector::Remove(size_t idx)
{
    if(idx < 1 || idx > size)
    {
        std::cout << "Invalid erase!" << std::endl;
    }
    else
    {
        std::shared_ptr<TVectorItem> del;
        std::shared_ptr<TVectorItem> prev_del;
        std::shared_ptr<TVectorItem> next_del = this->first;
        size--;
        if(idx == 1)
        {
            del = this->first;
            next_del = next_del->next;
            this->first = next_del;
        }
        else
        {
            for(int i = 1; i < idx; ++i)
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
/*-----Rhombus-----*/
const Rhombus& TVector::Last()
{
    std::shared_ptr<TVectorItem> node = this->first;
    while(node->next != nullptr)
    {
        node = node->next;
    }
    return *node->rhomb;
}
/*----destructor---*/

TVector::~TVector()
{
    std::cout << "TVector deleted" << std::endl;
}
/*----size_t---*/
size_t TVector::Length()
{
    return size;
}
/*----operator---*/

Rhombus& TVector::operator[](const size_t idx)
{
    std::shared_ptr<TVectorItem> idx_rhomb = this->first;
    for(int i = 1; i < idx; i++)
    {
        idx_rhomb = idx_rhomb->next;
    }
    return *idx_rhomb->rhomb;
}

std::ostream& operator<<(std::ostream& os, TVector& obj)
{
    if(obj.size == 0)
    {
        os << "TList is empty" << std::endl;
    }
    else
    {
    os << "Print rhombus" << std::endl;
    std::shared_ptr<TVectorItem> print = obj.first;
    os << '[';
    for(int i = 0; i < obj.size - 1; i++)
    {
        os << print->rhomb->Area() << " " << "," << " ";
        print = print->next;
    }
    os << print->rhomb->Area() << ']';
    os << std::endl;
    }
    return os;
}

