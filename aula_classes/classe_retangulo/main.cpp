#include <iostream>

#include "retangulo.h"

int main(){

    Retangulo r1;
    r1.largura(10);
    r1.comprimento(11);

    // funcao lambda
    auto mr = [](Retangulo r){
        std::cout << r.comprimento() << " x " << r.largura();
        std::cout << "Area: " << r.area() << "\n";
        std::cout << "Peri: " << r.perimetro() << "\n";
    };
    mr(r1);
}