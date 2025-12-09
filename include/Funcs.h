#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "Funcionario.h"

extern string nomeUsuario, telefoneUsuario, loginUsuario, temaUsuario;

extern bool validado;

void limparTerminal();
void aplicarTema(const string tema);
bool validarLogin();
void cadastrarFuncionario();
void elencarFuncionarios();
void atualizarFuncionario();
void excluirFuncionario();
void menuGenerico(string setor);
void Categorias();
void Clientes();
void Fornecedores();
void Funcionarios();
void Localizacoes();
void Pecas();
void PedidosCompra();
void Vendas();
void menuUsuario();
void iniciarMenu();