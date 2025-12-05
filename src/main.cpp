#include <string>
#include <iostream>
#include "Base.h"
#include "Pessoa.h"

using namespace std;

int main() 
{
    Pessoa pessoa("Fabio", "12345678");
    Pessoa pessoa2("Pettra", "23456781");

    cout << pessoa.getNome() << " tem id = " << pessoa.getId() << " e tem telefone = " << pessoa.getTelefone() << endl;
    cout << pessoa2.getNome() << " tem id = " << pessoa2.getId() << " e tem telefone = " << pessoa2.getTelefone();
}