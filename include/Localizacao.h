#pragma once

#include "Base.h"

class Localizacao : public Base {
private:
    string prateleira;
public:
    Localizacao(string prateleira) : prateleira(prateleira) {}
    string getPrateleira() const;
};