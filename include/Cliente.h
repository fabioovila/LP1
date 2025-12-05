#pragma once

#include "Pessoa.h"

class Cliente : public Pessoa {
private:
    string preferencia;
public:
    Cliente(const string nome, const string telefone, const string preferencia): Pessoa(nome, telefone), preferencia(preferencia){}
};