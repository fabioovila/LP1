#pragma once

#include "Base.h"

class Localizacao : public Base {
private:
    string prateleira;
public:
    Localizacao::Localizacao(string prateleira) : prateleira(prateleira) {}
};