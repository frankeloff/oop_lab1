#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>
#include "TVectorItem.h"
#include "rhombus.h"
#include <memory>

class TVector
{
public:
/*-----init-----*/
    TVector();
/*-----void-----*/
    void Remove(size_t idx);
    void Resize(const size_t new_size);
    void InsertLast(std::shared_ptr<Rhombus> &&rhomb);
    void RemoveLast();
/*-----Rhombus-----*/
    const Rhombus& Last();
/*-----bool-----*/
    bool Empty();
/*-----size_t-----*/
    size_t Length();
/*----operator-----*/
    Rhombus& operator[] (const size_t idx);
    friend std::ostream& operator<<(std::ostream& os, TVector& obj);
/*-----destructor-----*/
    ~TVector();
private:
    size_t size;
    std::shared_ptr<TVectorItem> first;
};

#endif//TVECTOR_H