#include "include/Funcionario.h"

string Funcionario::getLogin() const 
{
    return login;
}

void Funcionario::setLogin(const string novoLogin)
{
    login = novoLogin;
}