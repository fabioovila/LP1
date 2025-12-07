#include <string>
#include <iostream>
#include "include/Base.h"
#include "include/Categoria.h"
#include "include/Cliente.h"
#include "include/Fornecedor.h"
#include "include/Funcionario.h"
#include "include/Localizacao.h"
#include "include/Peca.h"
#include "include/pedidoCompra.h"
#include "include/Pessoa.h"
#include "include/Venda.h"

using namespace std;

int main() 
{
    string nome, telefone;
    cin >> nome >> telefone;
    
    Pessoa pessoa(nome, telefone);
    cout << pessoa.getNome() << " | " << pessoa.getTelefone() << endl; 
    
    // Pessoa pessoa("Fabio", "12345678");
    // Pessoa pessoa2("Pettra", "23456781");

    // pessoa2.exibirPessoa();
}