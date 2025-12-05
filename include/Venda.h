#pragma once

#include "Base.h"

class Venda : public Base {
private:
    float subTotal;
    int idFuncionario;
    int idCliente;
    string dataCompra;
public:
    Venda(float subTotal, int idFuncionario, int idCliente, string dataCompra) : subTotal(subTotal), idFuncionario(idFuncionario), idCliente(idCliente), dataCompra(dataCompra) {}
    float getSubTotal() const;
    int getIdFuncionario() const;
    int getIdCliente() const;
    string getDataCompra() const;
};