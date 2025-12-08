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
    ifstream file("output.txt");
    string linha;
    
    while (getline(file, linha)) {
        size_t separacaoLoginDados = linha.find(':');
        string login_arquivo = linha.substr(0, separacaoLoginDados);
        
        if (login_arquivo == tentativa) {
            nomeUsuario = login_arquivo;

            string dadosPermissaoTema = linha.substr(separacaoLoginDados + 1);

            size_t posLogin = dadosPermissaoTema.find(';');

            string permissao = dadosPermissaoTema.substr(0, posLogin);
            string tema = dadosPermissaoTema.substr(posLogin + 1);

            aplicarTema(tema);

            cout << "\nBem vindo, " << login_arquivo << "!" << endl;
            cout << "\nVocê tem nível de: " << permissao << endl;

            validado = true;
            return permissao;
        }
    }

    cout << "Login não encontrado :(" << endl;
}

int main() 
{
    // primeira coisa que tem que ter: login de funcionario(usuario) pra carregar nome de exibição e tema claro/escuro
    string permissaoUsuario;

    while (!validado) permissaoUsuario = validarLogin();

    cout << "\n e aí, vamos codar?" << endl;
    // string nome, telefone;
    // cin >> nome >> telefone;
    
    // Pessoa pessoa(nome, telefone);
    // cout << pessoa.getNome() << " | " << pessoa.getTelefone() << endl; 
    
    // Pessoa pessoa("Fabio", "12345678");
    // Pessoa pessoa2("Pettra", "23456781");

    // pessoa2.exibirPessoa();
}