#pragma once

#include "Pessoa.h"

class Funcionario : public Pessoa {
private:
    string login;
    string tema;
public:
    Funcionario(string nome, string telefone, string login) : Pessoa(nome, telefone), login(login){}

    string getLogin() const;
    string getTema() const;
    
    void setLogin(const string novoLogin);
    void setTema(const string novoTema);
};

