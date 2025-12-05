#pragma once

#include <string>
#include <iostream>

using namespace std;

class Base {
    private:
        static int num;
    public:
        static int recuperaNum();
    private:
    public:
        Base(int num);
        virtual ~Base() = 0;
};