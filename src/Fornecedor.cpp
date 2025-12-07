#include "Fornecedor.h"

string Fornecedor::getTipo() const
{
    return tipo;
}

void Fornecedor::setTipo(const string novoTipo)
{
    // ainda tenho que implementar tratamento de excecoes
    tipo = novoTipo;
}