#include "Localizacao.h"

string Localizacao::getPrateleira() const
{
    return prateleira;
}

void Localizacao::setPrateleira(const string novaPrateleira)
{
    // ainda tenho que implementar tratamento de excecoes
    prateleira = novaPrateleira;
}