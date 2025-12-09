#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include "CrudInterface.h"
#include "Base.h"
#include "Excecoes.h"
#include "Funcs.h" // Incluir para usar limparTerminal()

using namespace std;

template <typename T>
class RepositorioMemoriaBase : public CrudInterface {
protected:
    vector<T*> lista;
    string nomeEntidade; 

    virtual void validarEntidade(const T& entidade) const = 0;
    virtual T* coletarDadosCriacao() = 0; 
    virtual void coletarDadosAtualizacao(T* entidade) = 0; 
public:
    RepositorioMemoriaBase(const string& nome) : nomeEntidade(nome) {}

    virtual ~RepositorioMemoriaBase() {
        for (T* obj : lista) delete obj;
    }
    
    T* buscarPorId(int id) {
        for (T* obj : lista) {
            if (obj->getId() == id) return obj;
        }
        return nullptr;
    }
    
    void criar() override {
        T* novo = nullptr;
        try {
            novo = coletarDadosCriacao(); 
            lista.push_back(novo);
            cout << "\n" << nomeEntidade << " criado com sucesso (ID: " << novo->getId() << ")" << endl;
        } catch (const exception& e) {
            cout << "\nErro ao criar " << nomeEntidade << ": " << e.what() << endl;
            delete novo; 
        }
    }

    void ler() override {
        cout << "\n--- Lista " << nomeEntidade << "s ---" << endl;
        if (lista.empty()) {
            cout << "Nenhum registro cadastrado." << endl;
            return;
        }
        for (const T* obj : lista) {
            cout << obj->toString() << endl; 
        }
    }

    void atualizar() override {
        limparTerminal();
        ler(); 
        if (lista.empty()) return;

        cout << "\nAtualizar " << nomeEntidade << endl;
        int idBusca;
        cout << "Insira o ID do " << nomeEntidade << " que deseja atualizar: ";
        if (!(cin >> idBusca)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida." << endl; return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        T* existente = buscarPorId(idBusca);

        try {
            if (existente == nullptr) throw IdNaoEncontradoException(idBusca, nomeEntidade);
            
            coletarDadosAtualizacao(existente);
            validarEntidade(*existente); 

            cout << "\n" << nomeEntidade << " ID " << idBusca << " atualizado com sucesso!" << endl;
        } catch (const exception& e) {
            cout << "\nErro ao atualizar " << nomeEntidade << ": " << e.what() << endl;
        }
    }

    void excluir() override {
        limparTerminal();
        ler();
        if (lista.empty()) return;

        cout << "\nExcluir " << nomeEntidade << endl;
        int idBusca;
        cout << "Insira o ID do " << nomeEntidade << " que deseja excluir: ";
        if (!(cin >> idBusca)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida." << endl; return;
        }
        
        try {
            auto it = remove_if(lista.begin(), lista.end(),
                [&idBusca](T* obj) {
                    if (obj->getId() == idBusca) {
                        delete obj;
                        return true;
                    }
                    return false;
                });

            bool removido = (it != lista.end());
            lista.erase(it, lista.end());

            if (!removido) throw IdNaoEncontradoException(idBusca, nomeEntidade);
            cout << "\n" << nomeEntidade << " ID " << idBusca << " excluido com sucesso!" << endl;
        } catch (const exception& e) {
            cout << "\nErro ao excluir " << nomeEntidade << ": " << e.what() << endl;
        }
    }
};