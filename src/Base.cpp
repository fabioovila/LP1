#include "Base.h"

Base::Base(int novoId) : id(novoId) 
{
    if (novoId <= 0) {
        throw invalid_argument("ID deve ter um valor positivo");
    }
}

Base::~Base() {}

int Base::getId() const {
    return id;
}