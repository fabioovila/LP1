#pragma once

#include "Base.h"

class Localizacao : public Base {
private:
    string prateleira;
public:
    Localizacao(string prateleira) : prateleira(prateleira) {}
    
    virtual ~Localizacao() override;

    string getPrateleira() const;
    void setPrateleira(const string novaPrateleira);

    virtual string toString() const override;
};