#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>
#include "TVectorItem.h"
#include "rhombus.h"
#include "titerator.h"
#include <memory>

template <class T> class TVector
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
    template <class B> friend std::ostream& operator<<(std::ostream& os, TVector<B> &obj);
/*-----destructor-----*/
    ~TVector();
    TIterator<TVectorItem<T>, T> begin();
    TIterator<TVectorItem<T>, T> end();  
private:
    size_t size;
    std::shared_ptr<TVectorItem<T>> first;
};

#include "TVector.inl"

#endif//TVECTOR_H