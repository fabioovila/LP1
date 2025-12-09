#include <fstream>
#include "Funcs.h"
#include "Funcionario.h"

Funcionario::Funcionario(string nome, string telefone, string login, string tema)  : Pessoa(nome, telefone), login(login), tema(tema)
{
    ofstream file("usuarios.txt", ios::app);
    file << endl << login << ":" << nome << "," << telefone << ";" << tema;
    file.close();
}

string Funcionario::getLogin() const 
{
    return login;
}

string Funcionario::getTema() const
{
    return tema;
}

void Funcionario::setLogin(const string novoLogin)
{
    login = novoLogin;
}

void Funcionario::setTema(const string novoTema)
{
    tema = novoTema;
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
        }
    }
}

void cadastrarFuncionario()
{
    string nome, usuario, telefone, tema;
    cout << "Qual eh o nome do novo usuario? ";
    cin >> nome;
    cout << "Qual eh o telefone dele? ";
    cin >> telefone;
    cout << "Qual sera o login dele? ";
    cin >> usuario;
    cout << "Qual eh o tema preferido dele? (claro/escuro): ";
    cin >> tema;

    Funcionario novo(nome, telefone, usuario, tema);
}

void elencarFuncionarios()
{
    ifstream file("usuarios.txt");
    string linha;

    cout << endl;
    
    while(getline(file, linha))
    {
        size_t doispontos = linha.find(':');
        size_t virgula = linha.find(',');
        size_t pontoevirgula = linha.find(';');

        string login = linha.substr(0, doispontos);
        string nome = linha.substr(doispontos + 1, virgula - (doispontos + 1));
        string telefone = linha.substr(virgula + 1, pontoevirgula - (virgula + 1));
        string tema = linha.substr(pontoevirgula + 1);
              
        cout << "Nome: " << nome << " | Telefone: " << telefone << " | Login: " << login << " | Tema: " << tema << endl;
    }
}

void atualizarFuncionario()
{
    string nome;
    cout << "Voce quer atualizar qual usuario? ";
    cin >> nome;


}

void excluirFuncionario()
{

}