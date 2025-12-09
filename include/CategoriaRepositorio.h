#pragma once
#include "RepositorioMemoriaBase.h"
#include "Categoria.h"

class CategoriaRepositorio : public RepositorioMemoriaBase<Categoria> {
protected:
    void validarEntidade(const Categoria& entidade) const override;
    Categoria* coletarDadosCriacao() override;
    void coletarDadosAtualizacao(Categoria* entidade) override;
public:
    CategoriaRepositorio() : RepositorioMemoriaBase<Categoria>("Categoria") {}
};