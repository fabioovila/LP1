#include "Fornecedor.h"
#include <sstream>

Fornecedor::~Fornecedor() {}

std::string Fornecedor::toString() const {
    std::stringstream ss;
    ss << Pessoa::toString();
    ss << " | Tipo: " << getTipo();
    
    return ss.str();
}

string Fornecedor::getTipo() const
{
    return tipo;
}

void Fornecedor::setTipo(const string novoTipo)
{
    tipo = novoTipo;
}
