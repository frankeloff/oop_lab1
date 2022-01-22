#include <iostream>
#include "Modulo.h"

Modulo operator "" _classmodulo(const char* str, size_t size){
    int cnt = 0;
    std::string s = "";
    while (str[cnt] != ' '){
        s += str[cnt++];
    }
    double r = 0, j = 0;
    for (int i = 0; i < s.size(); ++i) {
        r *= 10;
        r += s[i] - '0';
    }
    s = "";
    while (str[cnt++] != '\0') {
        s += str[cnt];
    }
    for (int i = 0; i < s.size() - 1; ++i) {
        j *= 10;
        j += s[i] - '0';
    }
    Modulo g(r, j);
    return g;
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
    std::cout << "Literal class Modulo+: " << "12 5"_classmodulo << std::endl;
    std::cout << "Literal--: " << 12_minusone << std::endl;
}