#include <string>
#include <iostream>
#include "Base.h"
#include "Pessoa.h"

using namespace std;

int main() 
{
    string nome, telefone;
    cin >> nome >> telefone;
    
    Pessoa pessoa(nome, telefone);
    pessoa.exibirPessoa();
    
    // Pessoa pessoa("Fabio", "12345678");
    // Pessoa pessoa2("Pettra", "23456781");

    // pessoa2.exibirPessoa();
}