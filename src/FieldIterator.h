#pragma once
#include "Field.h"

class Iterator
{
private:
    int cell_x, cell_y;
    int width, height;
    const Field* field;

public:
    Iterator(const Field* f);
    Iterator(int i = 0, int j = 0);
    Iterator begin();
    Iterator end();

    void operator++();
    void operator--();
    bool operator==(const Iterator& field_2);
    bool operator!=(const Iterator& field_2);
    Cell& operator*();

    Cell& get_Cell();

    void next();
    void back();
    void up();
    void down();
    void left();
    void right();
};
