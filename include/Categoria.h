#pragma once

#include "Base.h"

class Categoria : public Base {
private:
    string nome;
    string localizacao;
public:
    Categoria(string nome, string localizacao) : nome(nome), localizacao(localizacao) {}
    
    string getNome() const;
    string getLocalizacao() const;
    void setNome(const string novoNome);
    void setLocalizacao(const string novaLocalizacao);

    virtual string toString() const override;
};