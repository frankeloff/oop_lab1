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
    void erase(int pos);
    void insert(Rhombus &&rhomb, int pos);
    void clear();
    void push_front(Rhombus &&rhomb);
    void pop_front();
    void push_back(Rhombus &&rhomb);
    void pop_back();
/*-----bool-----*/
    bool empty();
/*-----TVectorItem*-----*/
    TVectorItem* back();
    TVectorItem* front();
/*----operator-----*/
    friend std::ostream& operator<<(std::ostream& os, TVector& obj);
/*-----destructor-----*/
    ~TVector();
private:
    int size;
    TVectorItem *first;
};

#endif//TVECTOR_H