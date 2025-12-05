#pragma once

#include "Pessoa.h"

class Funcionario : public Pessoa {
private:
    string login;
public:
    Funcionario::Funcionario(string nome, string telefone, string login) : Pessoa(nome, telefone), login(login){}
};