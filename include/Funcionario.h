#pragma once

#include "Pessoa.h"
#include "CrudInterface.h"
#include "FileInterface.h"

class Funcionario : public Pessoa {
private:
    string login;
    string tema;
public:
    Funcionario(string nome, string telefone, string login) : Pessoa(nome, telefone), login(login){}
    Funcionario(string nome, string telefone, string login, string tema) : Pessoa(nome, telefone), login(login), tema(tema){}

    string getLogin() const;
    string getTema() const;
    
    void setLogin(const string novoLogin);
    void setTema(const string novoTema);
};

