#include <iostream>
#include "Modulo.h"

unsigned long long operator "" _plusone(unsigned long long a){
    a +=1;
    return a;
}

unsigned long long operator "" _minusone(unsigned long long a){
    a -=1;
    return a;
}

int main(){
    Modulo c(std::cin);
    Modulo a(10, 6);
    Modulo b(12, 5);
    std::cout << "Modulo objects"<< a << b << c << std::endl;
    std::cout << "Sum: " << a+b << std::endl;
    std::cout << "Division of residues " << a/b << std::endl;
    std::cout << "Multiplication of residuals " << a*b << std::endl;
    std::cout << "Sum " << c+b << std::endl;
    std::cout << "Operator -- : " << --a;
    std::cout << "Operator ++ : " << ++a;
    std::cout << "Literal++: " << 12_plusone << std::endl;
    std::cout << "Literal--: " << 12_minusone << std::endl;
}