#include "Categoria.h"
#include <sstream>

string Categoria::getNome() const 
{
    return nome;
}

string Categoria::getLocalizacao() const
{
    return localizacao;
}

void Categoria::setNome(const string novoNome)
{
    // ainda tenho que implementar tratamento de excecoes
    nome = novoNome;
}

void Categoria::setLocalizacao(const string novaLocalizacao)
{
    // ainda tenho que implementar tratamento de excecoes
    localizacao = novaLocalizacao;
}

string Categoria::toString() const {
    stringstream ss;
    ss << "ID: " << getId() << " | Nome: " << nome << " | Localizacao: " << localizacao;
    return ss.str();
}