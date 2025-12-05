#pragma once

class FileInterface {
public:
    virtual ~FileInterface() {}

    virtual void salvar() const = 0;
    virtual void carregar() const = 0;
};