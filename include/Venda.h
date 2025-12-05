#pragma once

#include "Base.h"

class Venda : public Base {
private:
    float subTotal;
    int idFuncionario;
    int idCliente;
    string dataCompra;
    // preciso implementar talvez um vector de pair para fazer a lista de itens e seus precos e depois calcular o valor total?
public:
    Venda(float subTotal, int idFuncionario, int idCliente, string dataCompra) : subTotal(subTotal), idFuncionario(idFuncionario), idCliente(idCliente), dataCompra(dataCompra) {}
    
    float getSubTotal() const;
    int getIdFuncionario() const;
    int getIdCliente() const;
    string getDataCompra() const;

    void setSubTotal(const float novoSubTotal);
    void setDataCompra(const string novaDataCompra);
    // sem set pros Ids pois ele eh automatico
};