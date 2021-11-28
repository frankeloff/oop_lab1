#ifndef MODULO_H
#define MODULO_H
#include <iostream>

class Modulo {
public:
    Modulo();
    Modulo(std::istream &is);
    Modulo(int value, int N);
    int operator +(Modulo& a);
    int operator -(Modulo& a);
    int operator *(Modulo& a);
    int operator /(Modulo& a);
    Modulo operator ++();
    Modulo operator --();
    bool operator ==(const Modulo& other);
    friend std::ostream& operator<<(std::ostream& os,const Modulo& a);
    ~Modulo();
private:
    int value;
    int N;
};

#endif // MODULO_H