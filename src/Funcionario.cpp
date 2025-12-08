#include "Funcionario.h"

string nomeDoArquivo = "usuarios.txt";

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
    // utilizar apenas para atualizar
    login = novoLogin;
}

void Funcionario::setTema(const string novoTema)
{
    // utilizar apenas para atualizar
    tema = novoTema;
}