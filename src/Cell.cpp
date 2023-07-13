#include "Cell.h"

Cell::Cell()
{
    this->pass = true;
    this->in = false;
    this->out = false;
    this->player_1 = false;
    this->element = nullptr;
    this->people = false;
    this->alcogol = false;
    this->armor = false;
    this->enemy = false;
    this->medicine = false;
    this->player_11 = nullptr;
}

Cell::~Cell(){};

void Cell::set_unpass(bool val)
{
    this->pass = val;
    this->in = false;
    this->out = false;
}

void Cell::set_in(bool val)
{
    this->pass = true;
    this->in = val;
    this->out = false;
}

void Cell::set_out(bool val)
{
    this->pass = true;
    this->in = false;
    this->out = val;
}

void Cell::set_player_1(bool val)
{
    this->player_1 = val;
}

void Cell::set_people(bool val)
{
    this->people = val;
}

void Cell::set_alcogol(bool val)
{
    this->alcogol = val;
}

void Cell::set_armor(bool val)
{
    this->armor = val;
}

void Cell::set_enemy(bool val)
{
    this->enemy = val;
}

void Cell::set_medicine(bool val)
{
    this->medicine = val;
}

bool Cell::get_pass()
{
    return this->pass;
}

bool Cell::get_in()
{
    return this->in;
}

bool Cell::get_out()
{
    return this->out;
}

bool Cell::get_player_1()
{
    return this->player_1;
}

void Cell::set_Element(Element* elem)
{
    this->element = elem;
}

void Cell::set_Player_1(Player_1* player)
{
    this->player_11 = player;
}

void Cell::delete_Element()
{
    if (this->element == nullptr)
    {
        return;
    }
    delete this->element;
    this->element = nullptr;
}

void Cell::delete_Player_1()
{
    if (this->player_11 == nullptr)
    {
        return;
    }
    delete this->player_11;
    this->player_11 = nullptr;
}

bool Cell::get_alcogol()
{
    return this->alcogol;
}

bool Cell::get_armor()
{
    return this->armor;
}

bool Cell::get_enemy()
{
    return this->enemy;
}

bool Cell::get_medicine()
{
    return this->medicine;
}

bool Cell::get_people()
{
    return this->people;
}

Element* Cell::get_Element()
{
    return this->element;
}