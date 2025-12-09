#include "Cliente.h"
#include <sstream>

Cliente::~Cliente() {}

string Cliente::toString() const {
    stringstream ss;
    ss << Pessoa::toString() << " | Preferencia: " << getPreferencia();
    return ss.str();
}

string Cliente::getPreferencia() const 
{
    return preferencia;
}

void Cliente::setPreferencia(const string novaPreferencia)
{
    preferencia = novaPreferencia;
}
