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

string nomeUsuario;

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

string validarLogin()
{
    cout << "\nInsira seu login: ";
    
    string tentativa;
    cin >> tentativa;
    cin.ignore();

    // cout << "\ntentativa = " << tentativa << endl << endl;
    ifstream file("texts/usuarios.txt"); // READ ONLY
    string linha;
    
    while (getline(file, linha)) {
        size_t separacaoLoginTema = linha.find(';');
        string login_arquivo = linha.substr(0, separacaoLoginTema);
        
        if (login_arquivo == tentativa) {
            string tema = linha.substr(separacaoLoginTema + 1);
            
            aplicarTema(tema);
            
            cout << "\nBem vindo, " << login_arquivo << "!" << endl;

            validado = true;
            return nomeUsuario;
        }
    }
    cout << "\nLogin não encontrado :(" << endl;
    return "";
}

int main() 
{
    limparTerminal();
    // suposto validador de Login
    while (!validado) nomeUsuario = validarLogin();


    // string nome, telefone;
    // cin >> nome >> telefone;
    
    // Pessoa pessoa(nome, telefone);
    // cout << pessoa.getNome() << " | " << pessoa.getTelefone() << endl; 
    
    // Pessoa pessoa("Fabio", "12345678");
    // Pessoa pessoa2("Pettra", "23456781");

    // pessoa2.exibirPessoa();
}