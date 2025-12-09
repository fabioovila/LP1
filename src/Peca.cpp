#include "Peca.h"

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

void Pecas() 
{
    
}