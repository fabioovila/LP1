#include "Peca.h"
#include <sstream>

Peca::~Peca() {}

string Peca::toString() const {
    stringstream ss;
    ss << "ID: " << getId() << " | Nome: " << nome << " | Preco: R$" << preco << " | Categoria: " << categoria;
    return ss.str();
}

string Peca::getNome() const
{
    return nome;
}

float Peca::getPreco() const
{
    return preco;
}

string Peca::getCategoria() const
{
    return categoria;
}

void Peca::setNome(const string novoNome)
{
    // ainda tenho que implementar tratamento de excecoes
    nome = novoNome;
}

void Peca::setPreco(const float novoPreco)
{
    // ainda tenho que implementar tratamento de excecoes
    preco = novoPreco;
}

void Peca::setCategoria(const string novaCategoria)
{
    // ainda tenho que implementar tratamento de excecoes
    categoria = novaCategoria;
}
