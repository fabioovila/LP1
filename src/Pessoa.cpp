#include "Pessoa.h"
#include "Base.h"

Pessoa::Pessoa(const string nome, const string telefone): Base(), nome(nome), telefone(telefone)
{}

Pessoa::~Pessoa() {}

string Pessoa::getNome() const
{
    return this->nome;
}

string Pessoa::getTelefone() const
{
    return this->telefone;
}