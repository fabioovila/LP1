#include "pedidoCompra.h"
#include <sstream>

string pedidoCompra::toString() const {
    stringstream ss;
    ss << "ID: " << getId() << " | Fornecedor ID: " << idFornecedor << " | Valor Total: R$" << valor;
    return ss.str();
}

int pedidoCompra::getIdFornecedor() const
{
    return idFornecedor;
}

float pedidoCompra::getValor() const
{
    return valor;
}

void pedidoCompra::setValor(const float novoValor)
{
    // ainda tenho que implementar tratamento de excecoes
    valor = novoValor;
}
