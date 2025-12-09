#include <fstream>
#include "Funcs.h"
#include "Funcionario.h"

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
