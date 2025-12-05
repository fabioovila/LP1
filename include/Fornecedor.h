#pragma once

#include "Pessoa.h"

class Fornecedor : public Pessoa {
private:
    string tipo;
public:
    Fornecedor(string nome, string telefone, string tipo) : Pessoa(nome, telefone), tipo(tipo) {}
    string getTipo() const;
};