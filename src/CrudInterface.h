#pragma once

#include "Base.h"

class CrudInterface {
public:
    virtual ~CrudInterface() {}

    virtual bool create(const Base& base) = 0;
    virtual Base* read(int id) = 0;
    virtual bool update(const Base& base) = 0;
    virtual bool deleter(int id) = 0;
};