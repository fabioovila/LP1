#include "PedidoCompraRepositorio.h"
#include "Funcs.h"
#include <sstream>

void PedidoCompraRepositorio::validarEntidade(const pedidoCompra& ped) const {
    if (ped.getValor() <= 0) 
        throw ValorInvalidoException("Valor Total");
    if (ped.getIdFornecedor() <= 0) 
        throw std::runtime_error("ID do Fornecedor invalido (deve ser > 0).");
}

pedidoCompra* PedidoCompraRepositorio::coletarDadosCriacao() {
    limparTerminal();
    cout << "--- CRIAR NOVO PEDIDO DE COMPRA ---" << endl;
    int idFornecedor;
    float valor;
    
    cout << "ID do Fornecedor: ";
    if (!(cin >> idFornecedor)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); throw std::invalid_argument("ID invalido."); }
    cout << "Valor Total: "; 
    if (!(cin >> valor)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); throw std::invalid_argument("Valor invalido."); }
    
    pedidoCompra* novo = new pedidoCompra(idFornecedor, valor);
    validarEntidade(*novo);
    return novo;
}

void PedidoCompraRepositorio::coletarDadosAtualizacao(pedidoCompra* existente) {
    float novoValor = -1.0f;
    cout << "Novo Valor Total (Atual: R$" << existente->getValor() << ", deixe 0 ou vazio para não alterar): ";
    
    string valorInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, valorInput);
    if (!valorInput.empty() && valorInput != "0") {
        try {
            novoValor = stof(valorInput);
            if (novoValor <= 0) throw ValorInvalidoException("Valor Total");
        } catch (...) {
            throw std::invalid_argument("Valor invalido.");
        }
    }
    
    if (novoValor > 0) existente->setValor(novoValor);
}

PedidoCompraRepositorio repoPedidosCompra;

void PedidosCompra() {
    int opcao = -1;
    while (opcao != 0) {
        menuGenerico("Pedido de Compra");
        if (!(cin >> opcao)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); opcao = -1; continue; }
        
        switch (opcao) {
            case 1: repoPedidosCompra.criar(); break;
            case 2: repoPedidosCompra.ler(); break;
            case 3: repoPedidosCompra.atualizar(); break;
            case 4: repoPedidosCompra.excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida." << endl; break;
        }
    }
}