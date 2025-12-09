#include "FuncionarioRepositorio.h"
#include <sstream>
#include <iostream>
#include <algorithm>

FuncionarioRepositorio::FuncionarioRepositorio()
{
    carregarDados();
}

FuncionarioRepositorio::~FuncionarioRepositorio() 
{
    salvarDados();
    for (Funcionario* f : listaFuncionarios) delete f;
}

void FuncionarioRepositorio::carregarDados()
{
    ifstream entrada(nomeArquivo);
    if (!entrada.is_open()) return;

    string linha;
    while (getline(entrada, linha))
    {
        if (linha.empty()) continue;

        size_t doispontos = linha.find(':');
        size_t virgula = linha.find(',');
        size_t pontoevirgula = linha.find(';');

        string login = linha.substr(0, doispontos);
        string nome = linha.substr(doispontos + 1, virgula - (doispontos + 1));
        string telefone = linha.substr(virgula + 1, pontoevirgula - (virgula + 1));
        string tema = linha.substr(pontoevirgula + 1);

        Funcionario* novo = new Funcionario(nome, telefone, login, tema); 
        listaFuncionarios.push_back(novo);
    }
    entrada.close();
}

void FuncionarioRepositorio::salvarDados()
{
    ofstream saida(nomeArquivo);
    if (!saida.is_open()) return;

    for (const Funcionario* f : listaFuncionarios) {
        saida << f->getLogin() << ":" << f->getNome() << ","
             << f->getTelefone() << ";" << f->getTema() << "\n"; 
    }
    saida.close();
}

Funcionario* FuncionarioRepositorio::fazerLogin(const string login) 
{
    for (Funcionario* f : listaFuncionarios) {
        if (f->getLogin() == login) return f;
    }
    return nullptr;
}

Funcionario* FuncionarioRepositorio::buscarPorLogin(const std::string login) {
    for (Funcionario* f : listaFuncionarios) {
        if (f->getLogin() == login) return f;
    }
    return nullptr;
}

void FuncionarioRepositorio::adicionar(const Funcionario& novoFuncionario)
{
    Funcionario* copia = new Funcionario(novoFuncionario.getNome(), novoFuncionario.getTelefone(), novoFuncionario.getLogin(), novoFuncionario.getTema());
    listaFuncionarios.push_back(copia);
}

void FuncionarioRepositorio::atualizar(const Funcionario& funcionarioAtualizado)
{
    for (Funcionario* existente : listaFuncionarios) {
        if(existente->getLogin() == funcionarioAtualizado.getLogin()) {
            existente->setLogin(funcionarioAtualizado.getLogin());
            existente->setTema(funcionarioAtualizado.getTema());
            existente->setNome(funcionarioAtualizado.getNome());
            existente->setTelefone(funcionarioAtualizado.getTelefone());
            return;
        }
    }
}

bool FuncionarioRepositorio::removerPorLogin(const std::string& login) {
    if (listaFuncionarios.size() == 1) {
        if (listaFuncionarios[0]->getLogin() == login) {
            //throw UltimoFuncionarioException();
            cout << "Lista de funcionarios nao pode ficar vazia!";
            return false;
        }
    }
    
    auto it = std::remove_if(listaFuncionarios.begin(), listaFuncionarios.end(),
        [&login](Funcionario* f) {
            if (f->getLogin() == login) {
                delete f;
                return true;
            }
            return false;
        });

    bool removido = (it != listaFuncionarios.end());
    listaFuncionarios.erase(it, listaFuncionarios.end());

    return removido;
}