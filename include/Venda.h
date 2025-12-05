#pragma once

#include "Base.h"

class Venda : public Base {
private:
    float subTotal;
    int idFuncionario;
    int idCliente;
    string data;
public:
    Venda(float subTotal, int idFuncionario, int idCliente, string data) : subTotal(subTotal), idFuncionario(idFuncionario), idCliente(idCliente), data(data) {}
};