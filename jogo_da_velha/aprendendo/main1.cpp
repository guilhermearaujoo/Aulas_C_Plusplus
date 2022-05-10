#include <iostream>
#include <fstream>
#include <ios>
using namespace std;

class person{
    public:
    int ident;
    std::string nome;
    int vitorias;
};

int main(){
    fstream arq;
    string nome = "texto.txt";
    arq.open(nome, ios::in);
    
    int cont=0;
    while(getline(arq, nome)){
        cont++;
    }

    cout << cont << endl;
    //person any;
    //string line;
    //while(getline(arq, line)){
   //     arq >> any.ident >> any.nome >> any.vitorias;
      //  cout << any.ident << endl << any.nome << endl << any.vitorias << endl;
    //}
    
}
/*
int main(){
    fstream arq;
    arq.open("texto.txt", ios::out);

    if(arq.is_open()){
        string nome = "Guilherme\n";
        int idade = 19;

        arq << nome << idade;
        arq.close();
    } else{
        cout << "Could not open the file";
    }

    fstream arq_o("texto.txt", ios::in);
    string name;
    int age;
    arq_o >> name >> age;
    cout << name << endl << age << endl;
    cout << age+1 << endl;
}
*/

/*
int main(){

    //ofstream, fstream, ifstream

    //ofstream arq;
    //arq.open("try.txt", ios::app); 
    //posiciona o cursor no final do arquivo e insere na sequencia.

    //arq.open("try.txt");
    //arq << "Guilherme Araujo";

    ofstream arq_o;
    arq_o.open("try.txt");
    arq_o << "Guilherme\n";
    arq_o << "Henrique\n";
    arq_o << "Matos\n";
    arq_o << "Araujo\n";

    arq_o.close();

    ifstream arq_i;
    arq_i.open("try.txt");

    if(arq_i.is_open()){
        //string nome, nome1, sobrenome, sobrenome1;
        //arq_i >> nome >> nome1 >> sobrenome >> sobrenome1;
        //cout << nome << nome1 << sobrenome << sobrenome1;

        string linha;
        while(getline(arq_i, linha)){
            cout << linha << endl;
        }
        arq_i.close();
    } else{
        cout << "Não foi possível abrir o arquivo" << endl;
    }
    

    return 0;
}
*/