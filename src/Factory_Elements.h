#pragma once
#include "Element.h"

class Factory_Element
{
private:
    int x, y;
public:
    virtual Element* createElement() = 0;
    virtual ~Factory_Element(){};
    void set_xy(int, int);
    int get_x();
    int get_y();
};
