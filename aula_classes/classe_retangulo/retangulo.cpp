#include "retangulo.h"

double Retangulo::largura(){
    return larg;
}

double Retangulo::comprimento(){
    return comp;
}

void Retangulo::comprimento(double c){
    comp = c;
}

void Retangulo::largura(double l){
    larg = l;
}

double Retangulo::perimetro(){
    return 2*comprimento() + 2*largura(); 
};

double Retangulo::area(){
    return comprimento() * largura();
}
