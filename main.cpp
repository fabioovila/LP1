#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "Base.h"
#include "Categoria.h"
#include "Cliente.h"
#include "Fornecedor.h"
#include "Funcionario.h"
#include "Localizacao.h"
#include "Peca.h"
#include "pedidoCompra.h"
#include "Pessoa.h"
#include "Venda.h"
#include "Funcs.h"

using namespace std;

int main() 
{
    limparTerminal();

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    // construtor para userLogado, nao para novo usuario
    Funcionario userLogado(nomeUsuario, telefoneUsuario, loginUsuario);
    
    // mostrando polimorfismo abaixo
    cout << "Bem vindo, " << userLogado.getNome() << "!" << endl; 

    // implementacao esta na funcs.cpp
    iniciarMenu();

    cout << "Programa encerrado! :)" << endl;
}