#pragma once
#include "RepositorioMemoriaBase.h"
#include "Localizacao.h"

class LocalizacaoRepositorio : public RepositorioMemoriaBase<Localizacao> {
protected:
    void validarEntidade(const Localizacao& entidade) const override;
    Localizacao* coletarDadosCriacao() override;
    void coletarDadosAtualizacao(Localizacao* entidade) override;
public:
    LocalizacaoRepositorio() : RepositorioMemoriaBase<Localizacao>("Localizacao") {}
};