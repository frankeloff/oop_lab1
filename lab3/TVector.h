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
    void erase(int pos);
    void insert(std::shared_ptr<Rhombus> &&rhomb, int pos);
    void clear();
    void push_front(std::shared_ptr<Rhombus> &&rhomb);
    void pop_front();
    void push_back(std::shared_ptr<Rhombus> &&rhomb);
    void pop_back();
/*-----bool-----*/
    bool empty();
/*-----TVectorItem*-----*/
    std::shared_ptr<TVectorItem> back();
    std::shared_ptr<TVectorItem> front();
/*----operator-----*/
    friend std::ostream& operator<<(std::ostream& os, TVector& obj);
/*-----destructor-----*/
    ~TVector();
private:
    int size;
    std::shared_ptr<TVectorItem> node;
};