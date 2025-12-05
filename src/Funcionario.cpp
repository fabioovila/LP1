#include "include/Funcionario.h"

string Funcionario::getLogin() const 
{
    return login;
}

void Funcionario::setLogin(const string novoLogin)
{
    // ainda tenho que implementar tratamento de excecoes
    login = novoLogin;
}