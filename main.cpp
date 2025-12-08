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
    cout << "\n[1] - Categorias" << "\n[2] - Clientes";
    cout << "\n[3] - Fornecedor" << "\n[4] - Funcionarios";
    cout << "\n[5] - Localizacoes" << "\n[6] - Peças";
    cout << "\n[7] - Pedidos de Compras" << "\n[8] - Vendas";
    cout << "\n[0] - Encerrar Programa" << endl;
}  

void menuGenerico(string setor) 
{
    cout << "\n[1] - Criar " << setor;
    cout << "\n[2] - Elencar " << setor << "s";
    cout << "\n[3] - Atualizar " << setor;
    cout << "\n[4] - Excluir " << setor;

    cout << "\nQual opcao desse setor deseja acessar? ";
}

void Categorias() {}
void Clientes() {}
void Fornecedores() {}

void Funcionarios(Funcionario user) 
{
    int opcaofuncionario = -1;

    while (opcaofuncionario != 0) 
    {
        menuGenerico("Funcionário");
        cin >> opcaofuncionario;
        
        switch (opcaofuncionario) {
            case 1:
                user.criar();
                break; 
            case 2:
                user.ler();
                break;
            case 3:
                user.atualizar();
                break;
            case 4:
                user.excluir();
                break;
        }
    }
}

void Localizacoes() {}
void Pecas() {}
void PedidosCompra() {}
void Vendas() {}

int main() 
{
    limparTerminal();

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    Funcionario userLogado(nomeUsuario, telefoneUsuario, loginUsuario);
    
    // mostrando polimorfismo abaixo
    cout << "Bem vindo, " << userLogado.getNome() << "!" << endl; 

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
                Categorias();
                break; 
            case 2:
                cout << "Setor Clientes selecionado" << endl;
                Clientes();
                break;
            case 3:
                cout << "Setor Fornecedores selecionado" << endl;
                Fornecedores();
                break;
            case 4:
                cout << "Setor Funcionarios selecionado" << endl;
                Funcionarios(userLogado);
                break;
            case 5:
                cout << "Setor Localização selecionado" << endl;
                Localizacoes();
                break;
            case 6:
                cout << "Setor Peças selecionado" << endl;
                Pecas();
                break;
            case 7:
                cout << "Setor Pedidos de Compra selecionado" << endl;
                PedidosCompra();
                break;
            case 8:
                cout << "Setor Vendas selecionado" << endl;
                Vendas();
                break;
            case 0:
                continue;
            default:
                cout << "Nenhum setor correspondente (default)" << endl;
                break;
        }
    }

    cout << "Programa encerrado! :)" << endl;
}