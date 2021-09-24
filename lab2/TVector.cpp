#include <iostream>
#include "TVector.h"
#include "point.h"
TVector::TVector()
{   
    vector = (Rhombus*)malloc(sizeof(Rhombus));
    std::cout << "TVector created" << std::endl;
}

void TVector::push(Rhombus &&rhomb)
{
    size++;
    vector = (Rhombus*) realloc (vector, size*sizeof(Rhombus));
    vector[size-1] = rhomb;
}

Rhombus TVector::pop()
{   
    Rhombus del = vector[size];
    size--;
    vector = (Rhombus*) realloc (vector, size*sizeof(Rhombus));
    return del;
}

std::ostream& operator<<(std::ostream& os, TVector& p){
    if(p.size == 0)
    {
        os << "Empty" << std::endl;
    }
    else
    {
        for(int i = 0; i < p.size; i++)
        {
            os << p.vector[i] << " ";
        }
        os << std::endl;
    }
    return os;
}

TVector::~TVector()
{
    free(vector);
    std::cout << "TVector deleted" << std::endl;
}
