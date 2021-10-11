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

// TVectorItem* TVector::back()
// {
//     TVectorItem* front = this->first;
//     while(front->next != nullptr)
//     {
//         front = front->next;
//     }
//     return front;
// }

// TVectorItem* TVector::front()
// {
//     return this->first;
// }

/*----void----*/

// void TVector::pop_back()
// {
//     TVectorItem* del = this->first;
//     TVectorItem* prev_del;
//     if(size == 0)
//     {
//         std::cout << "List is empty" << std::endl;
//     }
//     else
//     {
//         while(del->next != nullptr)
//         {
//             prev_del = del;
//             del = del->next;
//             delete prev_del;
//         }
//         delete del;
//         size = 0;
//         std::cout << "TVector deleted" << std::endl;
//     } 
// }

// void TVector::push_front(Rhombus &&rhomb)
// {
//     TVectorItem* value = new TVectorItem(rhomb);
//     if(size == 0)
//     {
//         this->first = value;
//         this->first->next = nullptr;
//         this->first = value;
//         size++;
//     }
//     else
//     {
//     value->next = this->first;
//     this->first = value;
//     size++;
//     }
// }

void TVector::Resize(const size_t new_size)
{
    if(new_size > size || size == new_size)
    {
        return;
    }
    for(int i = 0; i < size - new_size; i++)
    {
        TVectorItem* del = this->first;
        TVectorItem* save;
        while(del->next != nullptr)
        {
            save = del;
            del = del->next;
        }
        save->next = nullptr;
        delete del;
    }
    size = new_size;
}

void TVector::InsertLast(const Rhombus &&rhomb)
{
    TVectorItem* value = new TVectorItem(rhomb);
    if(size == 0)
    {
        this->first = value;
        this->first->next = nullptr;
        this->first = value;
        size++;
    }
    else 
    {  
        TVectorItem* end = this->first;
        while(end->next != nullptr)
        {
            end = end->next;
        }
        end->next = value;
        value->next = nullptr;
        size++;
    }
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
            TVectorItem* del = this->first;
            delete del;
        }
        else
        {
            TVectorItem* del = this->first;
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

// void TVector::pop_front()
// {
//     if(size == 0)
//     {
//         std::cout << "List is empty" << std::endl;
//     }
//     else if(size == 1)
//     {
//         size--;
//         delete this->first;
//     }
//     else
//     {
//     TVectorItem* del = this->first;
//     TVectorItem* save = this->first;
//     save = save->next;
//     this->first = save;
//     size--;
//     delete del;
//     }
// }

// void TVector::insert(Rhombus &&rhomb, int pos) //correct pos > 0!
// {
//     if(pos > size + 1 || pos < 1)
//     {
//         throw std::invalid_argument("Invalid Insert");
//     }
//     else
//     {
//         TVectorItem* ins = new TVectorItem(rhomb);
//         TVectorItem* prev_ins;
//         TVectorItem* next_ins = this->first;
//         size++;
//         if(pos == 1)
//         {
//             ins->next = this->first;
//             this->first = ins;
//         }
//         else if(pos > size)
//         {
//             while(next_ins->next != nullptr)
//             {
//                 next_ins = next_ins->next;
//             }
//             next_ins->next = ins;
//             ins->next = nullptr;
//         }
//         else
//         {
//             for(int i = 0; i < pos - 1; ++i)
//                 {
//                     prev_ins = next_ins;
//                     next_ins = next_ins->next;
//                 }
//             prev_ins->next = ins;
//             ins->next = next_ins;   
//         }
//     }  
// }

void TVector::Remove(size_t idx)
{
    if(idx < 1 || idx > size)
    {
        std::cout << "Invalid erase!" << std::endl;
    }
    else
    {
        TVectorItem* del;
        TVectorItem* prev_del;
        TVectorItem* next_del = this->first;
        size--;
        if(idx == 1)
        {
            del = this->first;
            next_del = next_del->next;
            this->first = next_del;
            delete del;
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
            delete del;
        }
    }
}

/*----destructor---*/

TVector::~TVector()
{
    TVectorItem* del = this->first;
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

Rhombus& TVector::operator[](const size_t idx)
{
    TVectorItem* idx_rhomb = this->first;
    for(int i = 1; i < idx; i++)
    {
        idx_rhomb = idx_rhomb->next;
    }
    return idx_rhomb->rhomb;
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
    TVectorItem* print = obj.first;
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

/*----size_t---*/

size_t TVector::Length()
{
    return size;
}
