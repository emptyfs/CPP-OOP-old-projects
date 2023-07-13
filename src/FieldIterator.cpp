#include "FieldIterator.h"

Iterator::Iterator(const Field* f)
{
    this->field = f;
    for (int i = 0; i < f->width; i++)
    {
        for (int j = 0; j < f->height; j++)
        {
            this->cell_x = i;
            this->cell_y = j;
        }
    }
}

Iterator::Iterator(int i, int j)
{
    this->cell_x = i;
    this->cell_y = j;
}

Iterator Iterator::begin()
{
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            if (this->field->ptr[i][j].get_in())
            {
                return Iterator(i,j);
            }
        }
    }
}

Iterator Iterator::end()
{
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            if (this->field->ptr[i][j].get_out())
            {
                return Iterator(i,j);
            }
        }
    }
}

void Iterator::next()
{
    if ((this->cell_y + 1) == this->height && (this->cell_x + 1) == this->width)
    {
        return;
    }
    if ((this->cell_y + 1) < this->height)
    {
        this->cell_y++;
    }
    else
    {
        this->cell_x++;
    }
}

void Iterator::back()
{
    if ((this->cell_y + 1) == 1 && (this->cell_x + 1) == 1)
    {
        return;
    }
    if ((this->cell_y + 1) > 1)
    {
        this->cell_y--;
    }
    else
    {
        this->cell_x--;
    }
}

void Iterator::up()
{
    if (this->cell_y > 0 && this->field->ptr[this->cell_x][this->cell_y - 1].get_pass())
    {
        this->cell_y--;
    }
}

void Iterator::down()
{
    if (this->cell_y < this->height && this->field->ptr[this->cell_x][this->cell_y + 1].get_pass())
    {
        this->cell_y++;
    }
}

void Iterator::left()
{
    if (this->cell_x > 0 && this->field->ptr[this->cell_x - 1][this->cell_y].get_pass())
    {
        this->cell_x--;
    }
}

void Iterator::right()
{
    if (this->cell_x < this->width && this->field->ptr[this->cell_x + 1][this->cell_y].get_pass())
    {
        this->cell_x++;
    }
}

void Iterator::operator++()
{
    this->next();
}

void Iterator::operator--()
{
    this->back();
}

bool Iterator::operator==(const Iterator& field_2)
{
    return this->cell_x == field_2.cell_x && this->cell_y == field_2.cell_y && this->field == field_2.field;
}

bool Iterator::operator!=(const Iterator& field_2)
{
    return this->cell_x != field_2.cell_x || this->cell_y != field_2.cell_y || this->field != field_2.field;
}

Cell& Iterator::get_Cell()
{
    return Field::object->ptr[this->cell_x][this->cell_y];
}

Cell& Iterator::operator*()
{
    return this->get_Cell();
}
