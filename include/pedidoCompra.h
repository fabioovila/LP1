#pragma once

#include "Base.h"

class pedidoCompra : public Base {
private:
    int idFornecedor;
    float valor;
public:
    pedidoCompra(int idFornecedor, float valor) : idFornecedor(idFornecedor), valor(valor) {}
    
    int getIdFornecedor() const;
    float getValor() const;

    void setValor(const float novoValor);
    // sem set pros Ids pois ele eh automatico
};