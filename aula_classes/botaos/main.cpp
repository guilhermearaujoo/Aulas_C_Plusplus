// Aula sobre classes - 16/05
#include <iostream>
namespace introo{
    class Conta{
    private:
        double m_saldo;
    public:
      void deposita(double valor){
          m_saldo += valor;
      }
    };
}


int main(){
    introo::Conta minha_cc;
    minha_cc.deposita(1000);
}