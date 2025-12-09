#include "ClienteRepositorio.h"
#include "Funcs.h"
#include <sstream>

void ClienteRepositorio::validarEntidade(const Cliente& cli) const {
    if (cli.getNome().empty() || cli.getTelefone().empty() || cli.getPreferencia().empty()) 
        throw CampoVazioException("Nome, Telefone ou Preferencia");
}

Cliente* ClienteRepositorio::coletarDadosCriacao() {
    limparTerminal();
    cout << "--- CRIAR NOVO CLIENTE ---" << endl;
    string nome, telefone, preferencia;
    
    cout << "Nome do Cliente: "; getline(cin, nome);
    cout << "Telefone: "; getline(cin, telefone);
    cout << "Preferencia: "; getline(cin, preferencia);
    
    Cliente* novoCliente = new Cliente(nome, telefone, preferencia);
    validarEntidade(*novoCliente);
    return novoCliente;
}

void ClienteRepositorio::coletarDadosAtualizacao(Cliente* existente) {
    string novoNome, novoTelefone, novaPreferencia;
    cout << "Novo Nome (Atual: " << existente->getNome() << "): "; getline(cin, novoNome);
    cout << "Novo Telefone (Atual: " << existente->getTelefone() << "): "; getline(cin, novoTelefone);
    cout << "Nova Preferencia (Atual: " << existente->getPreferencia() << "): "; getline(cin, novaPreferencia);
    
    if (!novoNome.empty()) existente->setNome(novoNome);
    if (!novoTelefone.empty()) existente->setTelefone(novoTelefone);
    if (!novaPreferencia.empty()) existente->setPreferencia(novaPreferencia);
}

ClienteRepositorio repoClientes;

void Clientes() {
    int opcao = -1;
    while (opcao != 0) {
        menuGenerico("Cliente");
        if (!(cin >> opcao)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); opcao = -1; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcao) {
            case 1: repoClientes.criar(); break;
            case 2: repoClientes.ler(); break;
            case 3: repoClientes.atualizar(); break;
            case 4: repoClientes.excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida." << endl; break;
        }
    }
}