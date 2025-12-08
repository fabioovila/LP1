#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "Base.h"
#include "Categoria.h"
#include "Cliente.h"
#include "Fornecedor.h"
#include "Funcionario.h"
#include "Localizacao.h"
#include "Peca.h"
#include "pedidoCompra.h"
#include "Pessoa.h"
#include "Venda.h"

using namespace std;

string nomeUsuario, telefoneUsuario, loginUsuario, temaUsuario;

bool validado = false;

const string ESCURO = "\033[40m\033[37m";
const string CLARO = "\033[47m\033[30m";

void limparTerminal()
{
    cout << "\033[2J\033[1;1H";
}

void aplicarTema(const string tema) 
{
    if (tema == "escuro") cout << ESCURO;
    if (tema == "claro") cout << CLARO;
}

bool validarLogin()
{
    cout << "\nInsira seu login: ";
    
    string tentativa;
    cin >> tentativa;
    cin.ignore();

    // cout << "\ntentativa = " << tentativa << endl << endl;
    ifstream file("texts/usuarios.txt");
    string linha;
    
    while (getline(file, linha)) {
        size_t doispontos = linha.find(':');
        string login_arquivo = linha.substr(0, doispontos);
        
        if (login_arquivo == tentativa) {
            loginUsuario = login_arquivo;

            size_t virgula = linha.find(',');
            size_t pontoevirgula = linha.find(';');
            
            nomeUsuario = linha.substr(doispontos + 1, virgula - (doispontos + 1));
            telefoneUsuario = linha.substr(virgula + 1, pontoevirgula - (virgula + 1));
            temaUsuario = linha.substr(pontoevirgula + 1);
            
            aplicarTema(temaUsuario);
            
            return true;
        }
    }
    cout << "\nLogin não encontrado :(" << endl;
    return false;
}

int main() 
{
    limparTerminal();

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    Funcionario user(nomeUsuario, telefoneUsuario, loginUsuario);
    
    cout << "Bem vindo, " << user.getNome() << "!" << endl;
}