#pragma once

#include "Base.h"
#include <string>

class Pessoa : public Base {
protected:
    string nome;
    string telefone;
public:
    Pessoa(const string nome, const string telefone);
    virtual ~Pessoa();
    
    string getNome() const;
    string getTelefone() const;

    void setNome(const string novoNome);
    void setTelefone(const string novoTelefone);

    virtual string toString() const override;
};