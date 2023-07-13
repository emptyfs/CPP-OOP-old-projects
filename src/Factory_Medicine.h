#pragma once
#include "Factory_Elements.h"
#include "Medicine.h"

class Factory_Medicine:public Factory_Element
{
public:
    Element* createElement();
};
