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
    // void insert(std::shared_ptr<Rhombus> &&rhomb, int pos);
    // void clear();
    // void push_front(std::shared_ptr<Rhombus> &&rhomb);
    // void pop_front();
    void Resize(const size_t new_size);
    void InsertLast(std::shared_ptr<Rhombus> &&rhomb);
    void RemoveLast();
/*-----bool-----*/
    bool empty();
/*-----size_t-----*/
    size_t Length();
/*-----TVectorItem*-----*/
    // std::shared_ptr<TVectorItem> back();
    // std::shared_ptr<TVectorItem> front();
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