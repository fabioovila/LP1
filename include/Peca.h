#pragma once

#include "Base.h"

class Peca : public Base {
private:
    string nome;
    float preco;
    string categoria;
public:
    Peca(string nome, float preco, string categoria) : nome(nome), preco(preco), categoria(categoria) {}

};