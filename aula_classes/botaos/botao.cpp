#include <iostream>

namespace introo{
    class botao{
    private:
    // true para apertado, false para solto
        bool position_m;

    public:
        void change_position(bool position){
            position_m = position;
        }

        bool get_position(){
            return position_m;
        }
    };
}

int main(){
    introo::botao b;
    b.change_position(true);
    if(b.get_position()){
        std::cout << "O botao está apertado" << std::endl;
    } else {
        std::cout << "O botao está solto" << std::endl;
    }   
}