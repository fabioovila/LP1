#include "Base.h"

int Base::proxId = 1;

Base::Base() :id(proxId++)
{}

Base::~Base() 
{}

int Base::getId() const 
{
    return id;
}