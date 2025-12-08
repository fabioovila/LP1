#pragma once

#include <string>

using namespace std;

class FileInterface {
public:
    virtual ~FileInterface() {}

    virtual void escreverArquivo() const = 0;
    virtual void lerArquivo() const = 0;
};