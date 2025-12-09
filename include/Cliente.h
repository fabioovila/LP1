#pragma once

#include "Pessoa.h"

class Cliente : public Pessoa {
private:
    string preferencia;
public:
    Cliente(const string nome, const string telefone, const string preferencia): Pessoa(nome, telefone), preferencia(preferencia){}
    
    virtual ~Cliente() override;
    
    string getPreferencia() const;
    void setPreferencia(const string novaPreferencia);

    virtual string toString() const override;
};