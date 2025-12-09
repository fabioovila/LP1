#include "LocalizacaoRepositorio.h"
#include "Funcs.h"
#include <sstream>

void LocalizacaoRepositorio::validarEntidade(const Localizacao& loc) const {
    if (loc.getPrateleira().empty()) 
        throw CampoVazioException("Prateleira");
}

Localizacao* LocalizacaoRepositorio::coletarDadosCriacao() {
    limparTerminal();
    cout << "--- CRIAR NOVA LOCALIZACAO ---" << endl;
    string prateleira;
    
    cout << "Prateleira: "; getline(cin, prateleira);
    
    Localizacao* novo = new Localizacao(prateleira);
    validarEntidade(*novo);
    return novo;
}

void LocalizacaoRepositorio::coletarDadosAtualizacao(Localizacao* existente) {
    string novaPrateleira;
    cout << "Nova Prateleira (Atual: " << existente->getPrateleira() << "): "; getline(cin, novaPrateleira);
    
    if (!novaPrateleira.empty()) existente->setPrateleira(novaPrateleira);
}

LocalizacaoRepositorio repoLocalizacoes;

void Localizacoes() {
    int opcao = -1;
    while (opcao != 0) {
        menuGenerico("Localizacao");
        if (!(cin >> opcao)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); opcao = -1; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcao) {
            case 1: repoLocalizacoes.criar(); break;
            case 2: repoLocalizacoes.ler(); break;
            case 3: repoLocalizacoes.atualizar(); break;
            case 4: repoLocalizacoes.excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida." << endl; break;
        }
    }
}