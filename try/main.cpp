#include "hello.h"
#include <iostream>

int main(){
    std::cout << "This is a test";
    teste n1;
    n1.change_x(10);
    std::cout << n1.get_x();
}