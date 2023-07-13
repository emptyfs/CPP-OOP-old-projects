#pragma once
#include "Element.h"

class People:public Element
{
private:
    int x;
    int y;
public:
    void operator+(Player_1&);
    void set_x(int k) {this->x = k;}
    void set_y(int m) {this->y = m;}
    int get_x() {return this->x;}
    int get_y() {return this->y;}
};
