#include "Pessoa.h"
#include "Base.h"
#include <sstream>

Pessoa::Pessoa(const string nome, const string telefone): Base(), nome(nome), telefone(telefone)
{}

Pessoa::~Pessoa() {}

string Pessoa::getNome() const
{
    return nome;
}

string Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setNome(const string novoNome)
{
    // ainda tenho que implementar tratamento de excecoes
    nome = novoNome;
}

void Pessoa::setTelefone(const string novoTelefone)
{
    // ainda tenho que implementar tratamento de excecoes
    telefone = novoTelefone;
}

string Pessoa::toString() const {
    stringstream ss;
    ss << "ID: " << getId() << " | Nome: " << getNome() << " | Tel: " << getTelefone();
    return ss.str();
}