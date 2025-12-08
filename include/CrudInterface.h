#pragma once

#include "Base.h"

class CrudInterface {
public:
    virtual ~CrudInterface() {}

    virtual void criar() = 0;
    virtual void ler() = 0;
    virtual void atualizar() = 0;
    virtual void excluir() = 0;
};