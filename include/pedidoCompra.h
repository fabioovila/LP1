#pragma once

#include "Base.h"

class pedidoCompra : public Base {
private:
    int idFornecedor;
    float valor;
    // preciso implementar talvez um vector de pair para fazer a lista de itens e seus precos e depois calcular o valor total?
public:
    pedidoCompra(int idFornecedor, float valor) : idFornecedor(idFornecedor), valor(valor) {}
    
    int getIdFornecedor() const;
    float getValor() const;

    void setValor(const float novoValor);
    // sem set pros Ids pois ele eh automatico
};  