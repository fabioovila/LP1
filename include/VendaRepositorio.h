#pragma once
#include "RepositorioMemoriaBase.h"
#include "Venda.h"

class VendaRepositorio : public RepositorioMemoriaBase<Venda> {
protected:
    void validarEntidade(const Venda& entidade) const override;
    Venda* coletarDadosCriacao() override;
    void coletarDadosAtualizacao(Venda* entidade) override;
public:
    VendaRepositorio() : RepositorioMemoriaBase<Venda>("Venda") {}
};