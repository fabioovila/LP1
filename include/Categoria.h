#pragma once

#include "Base.h"

class Categoria : public Base {
private:
    string nome;
    string localizacao;
public:
    Categoria(string nome, string localizacao) : nome(nome), localizacao(localizacao) {}
    void exibirCategoria() const;
};