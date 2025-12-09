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
#include "FuncionarioRepositorio.h"

using namespace std;

FuncionarioRepositorio repoFuncionarios;

int main() 
{

    limparTerminal();
    while (!validado) validado = validarLogin();
    limparTerminal();

    cout << "Bem vindo, " << nomeUsuario << "!" << endl; 

    iniciarMenu(); // implementacao esta na funcs.cpp

    if (repoFuncionarios.houveAlteracao()) cout << "Alteracoes ao arquivo 'usuarios.txt' salvas!\n";

    cout << "\nPrograma encerrado! :)" << endl;
}