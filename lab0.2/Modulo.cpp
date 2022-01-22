#include <iostream>
#include "Modulo.h"
#include <cmath>

Modulo::Modulo(){
    value = 1;
    N = 1;
}

Modulo::Modulo(std::istream &is){
    is >> value;
    is >> N;
}

Modulo::Modulo(int first, int second){
    value = first;
    N = second;
}

int Modulo::operator +(Modulo& a){
    return this->value%this->N + a.value%a.N;
}

int Modulo::operator -(Modulo& a){
    return this->value%this->N - a.value%a.N;
}

int Modulo::operator *(Modulo& a){
    return (this->value%this->N) * (a.value%a.N);
}

int Modulo::operator /(Modulo& a){
    return (this->value%this->N) / (a.value%a.N);
}

Modulo Modulo::operator ++(){
    this->N++;
    this->value++;
    return *this;
}

Modulo Modulo::operator --(){
    this->N--;
    this->value--;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Modulo& a){
    os << a.value << " " << a.N << std::endl;
    return os;
}

bool Modulo::operator==(const Modulo& other){
    return this->N == other.N && this->value == other.value;
}

Modulo::~Modulo(){
    std::cout << "Modulo has deleted" << std::endl;
}