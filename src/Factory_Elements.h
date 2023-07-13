#pragma once
#include "Element.h"

class Factory_Element
{
public:
    virtual Element* createElement() = 0;
};