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

    // suposto validador de Login
    while (!validado) validado = validarLogin();
    
    // mostrando polimorfismo abaixo
    cout << "Bem vindo, " << nomeUsuario << "!" << endl; 

    // implementacao esta na funcs.cpp
    iniciarMenu();

    // o arquivo usuarios.txt é atualizado ao terminar o programa
    cout << "Programa encerrado! :)" << endl;
}