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

void menuUsuario()
{
    cout << "\n[1] - Categorias" << "\n[2] - Cliente";
    cout << "\n[3] - Fornecedor" << "\n[4] - Funcionario";
    cout << "\n[5] - Localizacao" << "\n[6] - Peça";
    cout << "\n[7] - Pedido de Compra" << "\n[8] - Venda";
    cout << "\n[0] - Encerrar Programa" << endl;
}  
int main() 
{
    limparTerminal();

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    Funcionario user(nomeUsuario, telefoneUsuario, loginUsuario);
    
    cout << "Bem vindo, " << user.getNome() << "!" << endl;

    int opcao = -1;

    while (opcao != 0)
    {
        menuUsuario();
        cout << "\nQual menu deseja acessar agora, " << nomeUsuario << "? ";
        cin >> opcao;
        cout << endl;
        
        switch (opcao) {
            case 1:
                cout << "Setor Categorias selecionado" << endl;
                break; 
            case 2:
                cout << "Setor Clientes selecionado" << endl;
                break;
            case 3:
                cout << "Setor Fornecedores selecionado" << endl;
                break;
            case 4:
                cout << "Setor Funcionarios selecionado" << endl;
                break;
            case 5:
                cout << "Setor Localização selecionado" << endl;
                break;
            case 6:
                cout << "Setor Peças selecionado" << endl;
                break;
            case 7:
                cout << "Setor Pedido de Compra selecionado" << endl;
                break;
            case 8:
                cout << "Setor Vendas selecionado" << endl;
                break;
            case 0:
                continue;
            default:
                cout << "Nenhum setor correspondente (default)" << endl;
                break;
        }
    }

    cout << "\nPrograma encerrado! :)" << endl;
}