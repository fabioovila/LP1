#include "include/Cliente.h"

string Cliente::getPreferencia() const 
{
    return preferencia;
}

void Cliente::setPreferencia(const string novaPreferencia)
{
    preferencia = novaPreferencia;
}