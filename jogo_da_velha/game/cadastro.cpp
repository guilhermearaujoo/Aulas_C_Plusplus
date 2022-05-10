#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


int numero_pessoas(std::string nome_arq){

    std::ifstream arq;
    arq.open(nome_arq);
    if(arq.is_open()){
        std::string line;
        int cont=0;
        while(getline(arq, line, '\n')){
            cont++;
        }
    
        return cont;
        arq.close();
    } else {
        std::cout << "Ímpossivel abrir o arquivo" << std::endl;
        system("Pause");
    }
};

bool vazio(std::string nome_arq){

    int cont = numero_pessoas(nome_arq);
    if(cont == 0){
        
        return true;
    }
    return false;
};


void cadastra_pessoa(std::string nome_pessoa, std::string nome_arq, int ident=0){
    std::ofstream arq;
    int cont = numero_pessoas(nome_arq);

    if(cont!=0){
        arq.open(nome_arq, std::ios::app);
        ident = cont;
    } else{
        arq.open(nome_arq);
    }

    if(arq.is_open()){
        arq << std::setw(13) << ident << "     " << std::setw(8) << nome_pessoa << "     " << std::setw(10) << 0 << "\n";
    } else {
        std::cout << "Ímpossivel abrir o arquivo" << std::endl;
        system("Pause");
    }
    arq.close();
};

void mostra_arquivo(std::string nome_arq){
    std::fstream arq;
    arq.open(nome_arq, std::ios::in);
    if(arq.is_open()){
        if(!vazio(nome_arq)){
            std::cout << std::setw(13) << "Identificação" << "     " << std::setw(10) << "Nome" << "     " << std::setw(8) << "Vitórias" << std::endl << std::endl;

            std::string line;
            while(getline(arq, line, '\n')){
                std::cout << line << std::endl;
            }
            std::cout << std::endl;
            arq.close();
        } else{
            std::cout << "Arquivo Vazio" <<std::endl;
        }
    } else {
        std::cout << "Ímpossivel abrir o arquivo" << std::endl;
        system("Pause");
    }
};

void ganhador(std::string nome_arq, int ident){

    if(!vazio(nome_arq)){

        int cont = numero_pessoas(nome_arq);
        if(ident >= cont || ident < 0){
            std::cout << "Digite um identificador válido." << std::endl;
        }else {

            std::ifstream arq;
            arq.open(nome_arq);
            std::vector<std::string> all;
            std::string line;

            while(getline(arq, line)){
                all.push_back(line);
            }

            arq.close();
            
            char vitorias = all[ident][all[ident].size()-1];
            vitorias = char(int(vitorias) + 1);

            all[ident][all[ident].size()-1] = vitorias;
            

            std::ofstream o_arq;
            o_arq.open(nome_arq);

            for(int i=0; i < all.size(); i++){
                o_arq << all[i];
                o_arq << "\n";
            }
            
            o_arq.close();
        }
    } else{
        std::cout << "Por favor, digite um número válido!" << std::endl;
    }
};

void limpa_arquivo(std::string arq_nome){
    std::fstream arq;
    arq.open(arq_nome, std::ios::out);
    arq.close();
};

bool verifica_jogador(int ident, std::string nome_arq){
    int cont = numero_pessoas(nome_arq);

    for(int i=0; i<cont; i++){
        if(ident == i){
            return true;
        }
    }
    return false;
}
