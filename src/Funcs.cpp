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
#include "Funcs.h"
#include "FuncionarioRepositorio.h"

using namespace std;

string nomeUsuario, telefoneUsuario, loginUsuario, temaUsuario;
bool validado = false;

extern FuncionarioRepositorio repoFuncionarios;

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

    Funcionario* usuarioLogado = repoFuncionarios.fazerLogin(tentativa);

    if(usuarioLogado != nullptr) {
        nomeUsuario = usuarioLogado->getNome();
        temaUsuario = usuarioLogado->getTema();

        aplicarTema(temaUsuario);
        return true;
    }

    cout << "\nLogin não encontrado :(" << endl;
    return false;
}

void cadastrarFuncionario()
{
    string nome, login, telefone, tema;
    cout << "Qual e o nome do novo usuario? ";
    cin >> nome;
    cout << "Qual sera o login dele? ";
    cin >> login;
    cout << "Qual e o telefone dele? ";
    cin >> telefone;
    cout << "Qual e o tema preferido dele? ";
    cin >> tema;

    Funcionario novo(nome, telefone, login, tema);

    repoFuncionarios.adicionar(novo);
    cout << "\nFuncionario cadastrado na memoria!" << endl;
}

void elencarFuncionarios()
{
    const vector<Funcionario*>& lista = repoFuncionarios.listarFuncionarios();

    for (const Funcionario* f : lista) {
        cout << "Nome: " << f->getNome() << " | Telefone: " << f->getTelefone() 
             << " | Login: " << f->getLogin() << " | Tema: " << f->getTema() << endl;
    }
}

void atualizarFuncionario()
{
    string loginBusca;
    cout << "Insira o login do usuario que deseja atualizar: ";
    cin >> loginBusca;

    Funcionario* existente = repoFuncionarios.buscarPorLogin(loginBusca);

    if (existente == nullptr) {
        cout << "Usuario nao encontrado" << endl;
        return;
    }

    string novoTema;
    cout << "Novo tema para " << existente->getNome() << ": ";
    cin >> novoTema;

    existente->setTema(novoTema);

    repoFuncionarios.atualizar(*existente);

    cout << "Tema de " << existente->getNome() << " atualizado na memoria!" << endl;
}

void excluirFuncionario()
{
    extern FuncionarioRepositorio repoFuncionarios; 
    
    string loginBusca;
    cout << "Insira o login do usuario que deseja excluir: ";
    cin >> loginBusca;

    bool sucesso = repoFuncionarios.removerPorLogin(loginBusca); 
    
    if (sucesso) cout << "\nFuncionario com login '" << loginBusca << "' excluido da memoria!" << endl;
    else cout << "\nUsuario com login '" << loginBusca << "' nao encontrado." << endl;
}

void Funcionarios() 
{
    int opcaofuncionario = -1;

    while (opcaofuncionario != 0) 
    {
        menuGenerico("Funcionário");
        cin >> opcaofuncionario;
        
        switch (opcaofuncionario) {
            case 1:
                cadastrarFuncionario();
                break; 
                
            case 2:
                elencarFuncionarios();
                break;
                
            case 3:
                atualizarFuncionario();
                break;
                
            case 4:
                excluirFuncionario();
                break;
                
            case 0:
                break;
                
            default:
                break;
        }
    }
}


void menuGenerico(string setor) 
{
    cout << "\n[1] - Criar " << setor;
    cout << "\n[2] - Elencar " << setor << "s";
    cout << "\n[3] - Atualizar " << setor;
    cout << "\n[4] - Excluir " << setor;
    cout << "\n[0] - Sair desse setor\n";

    cout << "\nQual opcao desse setor deseja acessar? ";
}

void opcoesUsuario()
{
    cout << "\n[1] - Categorias" << "\n[2] - Clientes";
    cout << "\n[3] - Fornecedor" << "\n[4] - Funcionarios";
    cout << "\n[5] - Localizacoes" << "\n[6] - Peças";
    cout << "\n[7] - Pedidos de Compras" << "\n[8] - Vendas";
    cout << "\n[0] - Encerrar Programa" << endl;
}  

void iniciarMenu()
{
    int opcao = -1;
    while (opcao != 0)
    {
        opcoesUsuario();
        cout << "\nQual menu deseja acessar agora, " << nomeUsuario << "? ";
        cin >> opcao;
        cout << endl;
        
        switch (opcao) {
            case 1:
                Categorias();
                break; 
            case 2:
                Clientes();
                break;
            case 3:
                Fornecedores();
                break;
            case 4:
                Funcionarios();
                break;
            case 5:
                Localizacoes();
                break;
            case 6:
                Pecas();
                break;
            case 7:
                PedidosCompra();
                break;
            case 8:
                Vendas();
                break;
            case 0:
                break;
            default:
                cout << "Nenhum setor correspondente (default)" << endl;
                break;
        }
    }
}