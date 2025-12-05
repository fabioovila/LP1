#include "include/Categoria.h"

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
    nome = novoNome;
}

void Categoria::setLocalizacao(const string novaLocalizacao)
{
    localizacao = novaLocalizacao;
}