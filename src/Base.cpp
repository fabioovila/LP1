#include "Base.h"

int Base::num = 0;

Base::Base(int num) : num(num) {
    num++;
}

Base::~Base() {}

int Base::recuperaNum()
{
    return num;
}