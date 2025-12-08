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

const string ESCURO = "\033[40m\033[37m";
const string CLARO = "\033[47m\033[30m";

int main() 
{
    limparTerminal();

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    Funcionario userLogado(nomeUsuario, telefoneUsuario, loginUsuario);
    
    // mostrando polimorfismo abaixo
    cout << "Bem vindo, " << userLogado.getNome() << "!" << endl; 

    iniciarMenu(userLogado);

    cout << "Programa encerrado! :)" << endl;
}