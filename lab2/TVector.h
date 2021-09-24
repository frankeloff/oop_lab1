#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>
#include "rhombus.h"

class TVector
{
public:
    TVector();
    void push(Rhombus &&rhomb);
    Rhombus pop();
    friend std::ostream& operator<<(std::ostream& os, TVector &other);
    ~TVector();

private:
    Rhombus *vector;
    int size = 0;
};

#endif /*TVECTOR_H*/