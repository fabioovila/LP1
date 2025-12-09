#pragma once

#include "Pessoa.h"

class Fornecedor : public Pessoa {
private:
    string tipo;
public:
    Fornecedor(string nome, string telefone, string tipo) : Pessoa(nome, telefone), tipo(tipo) {}
    
    virtual ~Fornecedor() override;

    string getTipo() const;
    void setTipo(const string novoTipo);

    virtual string toString() const override;
};