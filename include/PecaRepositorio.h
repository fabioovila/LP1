#pragma once
#include "RepositorioMemoriaBase.h"
#include "Peca.h"

class PecaRepositorio : public RepositorioMemoriaBase<Peca> {
protected:
    void validarEntidade(const Peca& entidade) const override;
    Peca* coletarDadosCriacao() override;
    void coletarDadosAtualizacao(Peca* entidade) override;
public:
    PecaRepositorio() : RepositorioMemoriaBase<Peca>("Peca") {}
};