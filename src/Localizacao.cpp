#include "Localizacao.h"
#include <sstream>

Localizacao::~Localizacao() {}

string Localizacao::toString() const {
    stringstream ss;
    ss << "ID: " << getId() << " | Prateleira: " << prateleira;
    return ss.str();
}

string Localizacao::getPrateleira() const
{
    return prateleira;
}

void Localizacao::setPrateleira(const string novaPrateleira)
{
    // ainda tenho que implementar tratamento de excecoes
    prateleira = novaPrateleira;
}
