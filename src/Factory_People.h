#pragma once
#include "Factory_Elements.h"
#include "People.h"

class Factory_People:public Factory_Element
{
public:
    Element* createElement();
};
