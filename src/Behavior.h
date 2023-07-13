#pragma once
#include "1_Player.h"

class Behavior
{
private:
    int x,y;
public:
    virtual void operator-(Player_1&) = 0;
    virtual ~Behavior(){};
    void set_xy(int, int);
    int get_x();
    int get_y();
};
