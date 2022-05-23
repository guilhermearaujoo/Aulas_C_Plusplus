#ifndef RETANGULO_H
#define RETANGULO_H

#include <iostream>


class Retangulo{
public:
    double comp=1;
    double larg=1;

    double perimetro();
    double area();
    double largura();
    double comprimento();
    void largura(double l);
    void comprimento(double c);
};

#endif
