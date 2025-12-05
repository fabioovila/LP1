#include "include/Peca.h"

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
    nome = novoNome;
}

void Peca::setPreco(const float novoPreco)
{
    preco = novoPreco;
}

void Peca::setCategoria(const string novaCategoria)
{
    categoria = novaCategoria;
}