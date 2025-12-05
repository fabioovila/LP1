#include "include/pedidoCompra.h"

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
    valor = novoValor;
}