#include <iostream>
#include <stdlib.h>
#include "cadastro.cpp"
#include "jogo.cpp"

using namespace std;

string nome_arq = "registro.txt";

bool option(){
    cout << "Sua opção [s] [n]: ";
    char opt;
    cin >> opt;

    while(!((opt == 'S' || opt == 's') || (opt=='N'|| opt=='n'))){
        
        cout << "Digite uma opção válida!" << endl;
        cout << "Sua opção [s] [n]: ";
        cin >> opt;
    }

    if((opt == 'S' || opt == 's')){
        return true;
    }

    return false;
}
    
int option_ident(int ident){
    if(verifica_jogador(ident, nome_arq)){
        cout << "Você selecionor a identificação " << ident << endl << endl;
    } else{
        if(ident == -1){
            exit(0);
        }
        cout << "\nOpção de jogador inválida!" << endl;
        cout << "Digite uma identificação válida: ";
        cin >> ident;
        option_ident(ident);
    }
    return ident;
}


void interface_jogo(){

    char novamente= true;
    do{
        cout << "\n\n***************************************\n";
        cout << "             Jogo da Velha             \n";
        cout << "***************************************\n\n";

        cout << "Para começar o jogo e necessário fazer o cadastro dos jogadores." << endl << "Os jogadores já possuem cadastro?" << endl;

        char opt;
        opt = option();
        int jogador1;
        int jogador2;
        int resultado;
        bool redireciona = false;

        if(opt){
            if(!vazio(nome_arq)){
                mostra_arquivo(nome_arq);
                cout << "Digite o número da identificação dos jogadores." << endl;
                
                cout << "Primeiro jogador: ";
                
                cin >> jogador1;
                jogador1 = option_ident(jogador1);
                
                cout << "Segundo jogador: ";
                cin >> jogador2;
                jogador2 = option_ident(jogador2);
            } else{
                cout << "Arquivo vazio, por favor, cadastre os jogadores!" << endl << endl;
                redireciona = true;
            }
        }

        if(opt==false || redireciona == true){
            cout << endl << "Digite o nome do primeiro jogador (sem espaços): ";
            string nome1;
            cin >> nome1;
            cadastra_pessoa(nome1, nome_arq);
            jogador1 = numero_pessoas(nome_arq) - 1;
            cout << "\nSua identificação é " << jogador1 << endl;

            cout << endl << "Digite o nome do segundo jogador (sem espaços): ";

            string nome2;
            cin >> nome2;
            cadastra_pessoa(nome2, nome_arq);
            jogador2 = numero_pessoas(nome_arq) - 1;
            cout << "\nSua identificação é " << jogador2 << endl;

            cout << endl <<"Jogadores registrados com sucesso!" << endl;
            mostra_arquivo(nome_arq);
        }

        cout << "O Jogador com identificação " << jogador1 << " será o [X]" << endl;
        cout << "O Jogador com identificação " << jogador2 << " será o [O]" << endl << endl;
        resultado = jogo();

        switch(resultado)
        {
            case(0): 
                cout << endl << "Jogador 1 [X] Ganhou!" << endl;
                ganhador(nome_arq, jogador1); 
                break;
            case(1): 
                cout << endl << endl << "Jogador 2 [O] Ganhou!" << endl;
                ganhador(nome_arq, jogador2);
                break;
        default:
            cout << endl << endl << "É um empate!\n";
        }

        cout <<"\n\n************************" << endl;
        cout << "       FIM DE JOGO      " << endl;
        cout << "************************" << endl<<endl;

        mostra_arquivo(nome_arq);

        cout << endl << "Deseja jogar novamente? ";
        novamente = option();
    }while(novamente);
}

int main(){

    bool funcionar = true;

    cout << "*********************************" << endl;
    cout << "ESSE PRPGRAMA É UM JOGO DA VELHA." << endl;
    cout << "*********************************" << endl;

    while(funcionar){

        cout << "O que quer fazer? " << endl;
        cout << "[1] Jogar" << endl;
        cout << "[2] Ver o placar" << endl;
        cout << "[3] Sair"<< endl;
        cout << "\nQual sua opção: ";

        int opt;
        cin >> opt;
        bool novamente = true;

        while(novamente){
            if(opt==1 || opt ==2 || opt ==3){
                novamente = false;
            } else{
                cout << "\n\nOpção inválida!!! Tente novamente" << endl;
                cout << "Qual sua opção: ";
                cin >> opt;
            };
        };
        
        switch(opt)
        {
            case(1):
                interface_jogo();
                break;
            case(2): 
                mostra_arquivo(nome_arq);
                break;
            case(3):
                funcionar = false;
                cout <<"\n\n*******************************" << endl;
                cout << "FIM DO PROGRAMA, VOLTE SEMPRE!" << endl;
                cout <<"*******************************" << endl;
                break;
            default:
                break;
        };
    };
}