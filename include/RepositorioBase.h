#pragma once

#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
#include "CrudInterface.h"
#include "FileInterface.h"
#include "Base.h"
#include "Excecoes.h"

// Classe Abstrata Genérica para Repositórios
template <typename T>
class RepositorioBase : public CrudInterface, public FileInterface {
protected:
    vector<T*> lista;
    string nomeArquivo;

    // Métodos abstratos para serialização/deserialização
    virtual void salvarObjeto(ofstream& saida, const T* objeto) const = 0;
    virtual T* carregarObjeto(const string& linha) = 0;

    // Método abstrato para validação de dados (Usa Excecoes.h)
    virtual void validarEntidade(const T& entidade) const = 0;

    void carregarDados() override {
        ifstream entrada(nomeArquivo);
        if (!entrada.is_open()) return;

        string linha;
        while (getline(entrada, linha)) {
            if (linha.empty()) continue;
            T* objeto = carregarObjeto(linha);
            if (objeto) lista.push_back(objeto);
        }
        entrada.close();
    }

    void salvarDados() override {
        ofstream saida(nomeArquivo);
        if (!saida.is_open()) return;

        for (const T* obj : lista) {
            salvarObjeto(saida, obj);
            saida << "\n";
        }
        saida.close();
    }

public:
    RepositorioBase(const string& arquivo) : nomeArquivo(arquivo) {
        carregarDados();
    }

    virtual ~RepositorioBase() {
        salvarDados();
        for (T* obj : lista) delete obj;
    }

    // Método de busca comum
    T* buscarPorId(int id) {
        for (T* obj : lista) {
            if (obj->getId() == id) return obj;
        }
        return nullptr;
    }

    // Método de listagem (ler) comum
    void ler() override {
        // Implementação básica de 'ler'
        if (lista.empty()) {
            cout << "Nenhum registro cadastrado em " << nomeArquivo << "." << endl;
            return;
        }
        for (const T* obj : lista) {
            cout << obj->toString() << endl;
        }
    }
    
    const vector<T*>& getLista() const { return lista; }
};