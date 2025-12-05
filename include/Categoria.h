#pragma once

#include "Base.h"

class Categoria : public Base {
private:
    string nome;
    string localizacao;
public:
    Categoria::Categoria(string nome, string localizacao) : nome(nome), localizacao(localizacao) {}
};