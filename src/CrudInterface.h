#pragma once

#include "Base.h"

class CrudInterface {
public:
    virtual ~CrudInterface() {}

    virtual bool criar(const Base& base) = 0;
    virtual Base* ler(int id) = 0;
    virtual bool atualizar(const Base& base) = 0;
    virtual bool excluir(int id) = 0;
};