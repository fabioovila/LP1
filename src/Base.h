#pragma once

#include <string>
#include <iostream>

using namespace std;

class Base {
    private:
        const int id;
    public:
        Base(int novoId);
        virtual ~Base() = 0;
        int getId() const;  
};