#include "include/Venda.h"

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