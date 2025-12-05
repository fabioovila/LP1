#include "include/Fornecedor.h"

string Fornecedor::getTipo() const
{
    return tipo;
}

void Fornecedor::setTipo(const string novoTipo)
{
    tipo = novoTipo;
}