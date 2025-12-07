#include "Venda.h"

float Venda::getSubTotal() const
{
    return subTotal;
}

int Venda::getIdFuncionario() const
{
    return idFuncionario;
}

int Venda::getIdCliente() const
{
    return idCliente;
}

string Venda::getDataCompra() const
{
    return dataCompra;
}

void Venda::setSubTotal(const float novoSubTotal)
{
    // ainda tenho que implementar tratamento de excecoes
    subTotal = novoSubTotal;
}

void Venda::setDataCompra(const string novaDataCompra)
{
    // ainda tenho que implementar tratamento de excecoes
    dataCompra = novaDataCompra;
}