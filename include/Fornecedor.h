#pragma once

#include "Pessoa.h"

class Fornecedor : public Pessoa {
private:
    string tipo;
public:
    Fornecedor::Fornecedor(string nome, string telefone, string tipo) : Pessoa(nome, telefone), tipo(tipo) {}
};