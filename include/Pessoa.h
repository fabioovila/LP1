#pragma once

#include "Base.h"
#include <string>

class Pessoa : public Base {
private:
    string nome;
    string telefone;
public:
    Pessoa(const string nome, const string telefone);
    virtual ~Pessoa();
    
    string getNome() const;
    string getTelefone() const;
};