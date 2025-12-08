#pragma once

#include "Base.h"

class Peca : public Base {
private:
    string nome;
    float preco;
    string categoria;
public:
    Peca(string nome, float preco, string categoria) : nome(nome), preco(preco), categoria(categoria) {}
    
    string getNome() const;
    float getPreco() const;
    string getCategoria() const;

    void setNome(const string novoNome);
    void setPreco(const float novoPreco);
    void setCategoria(const string novaCategoria);
};