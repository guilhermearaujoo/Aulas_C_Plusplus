#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class person{
    public:
    int ident;
    std::string nome;
};

int main(){

    ofstream arq;
    arq.open("text.txt");

    arq << "Guilherme" << " " << 0 << "\n";
    arq << "Guilherme" << " " << 0 << "\n";

    arq.close();

    ifstream iarq;
    iarq.open("text.txt");
    string line;
    vector<person> any;
    person one;
    while(getline(iarq, line, '\n')){
        iarq >> one.nome >> one.ident;
        any.push_back(one);
    }


    for(int i=0; i < any.size(); i++){
        cout << any[i].nome << " " << any[i].ident << "\n";
    }


    /*vector<person> any;

    person one;
    int x = 4;
    while(x>0){
        one.ident = x;
        one.nome = "Teste";
        one.vitorias = 10;
        any.push_back(one);
        x--;
    }

    for(int i=0; i<(any.size()); i++){
        cout << any[i].ident << endl;
    }

    cout<<any.size() << endl;
    cout << any[3].nome;
    */
}