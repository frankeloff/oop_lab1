#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>
#include "TVectorItem.h"
#include "rhombus.h"

class TVector
{
public:
/*-----init-----*/
    TVector();
/*-----void-----*/
    void Remove(size_t idx);
    // void insert(Rhombus &&rhomb, int pos);
    // void pop_back();
    // void push_front(Rhombus &&rhomb);
    // void pop_front();
    void Resize(const size_t new_size);
    void InsertLast(const Rhombus &&rhomb);
    void RemoveLast();
/*-----bool-----*/
    bool empty();
/*-----TVectorItem*-----*/
    // TVectorItem* back();
    // TVectorItem* front();
/*----size_t-----*/
    size_t Length();
/*----operator-----*/
    Rhombus& operator[] (const size_t idx);
    friend std::ostream& operator<<(std::ostream& os, TVector& obj);
/*-----destructor-----*/
    ~TVector();
private:
    size_t size;
    TVectorItem *first;
};

#endif//TVECTOR_H