#pragma once

#include <string>
#include <iostream>

using namespace std;

class Base {
private:
    static int proxId;
    const int id;

public:
    Base();
    virtual ~Base() = 0;

    int getId() const;

    virtual string toString() const = 0;
};