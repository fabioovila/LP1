#pragma once

#include <stdexcept>
#include <string>

class CampoVazioException : public std::runtime_error {
public:
    CampoVazioException(const std::string& campo)
        : std::runtime_error("Erro: O campo '" + campo + "' nao pode ser vazio.") {}
};

class IdNaoEncontradoException : public std::runtime_error {
public:
    IdNaoEncontradoException(int id, const std::string& tipo)
        : std::runtime_error("Erro: " + tipo + " com ID " + std::to_string(id) + " nao encontrado.") {}
};

class ValorInvalidoException : public std::runtime_error {
public:
    ValorInvalidoException(const std::string& campo)
        : std::runtime_error("Erro: O campo '" + campo + "' deve ter um valor positivo.") {}
};