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
    this->opponents = nullptr;
    this->behavior_people = nullptr;
    this->behavior_steal_alco = nullptr;
    this->behavior_to_start = nullptr;
    this->b1 = false;
    this->b2 = false;
    this->b3 = false;
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

void Cell::set_Opponents(Opponents<Behavior>* opponents)
{
    this->opponents = opponents;
}

void Cell::set_Behavior_people(Behavior_people* behavior_people)
{
    this->behavior_people = behavior_people;
}

void Cell::set_Behavior_steal_alco(Behavior_steal_alco* behavior_steal_alco)
{
    this->behavior_steal_alco = behavior_steal_alco;
}

void Cell::set_Behavior_to_start(Behavior_to_start* behavior_to_start)
{
    this->behavior_to_start = behavior_to_start;
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

void Cell::set_b1(bool val)
{
    b1 = val;
}

void Cell::set_b2(bool val)
{
    b2 = val;
}

void Cell::set_b3(bool val)
{
    b3 = val;
}

bool Cell::get_b1()
{
    return b1;
}

bool Cell::get_b2()
{
    return b2;
}

bool Cell::get_b3()
{
    return b3;
}

Opponents<Behavior>* Cell::get_Opponents()
{
    return opponents;
}

Behavior_people* Cell::get_Behavior_people()
{
    return behavior_people;
}

Behavior_steal_alco* Cell::get_Behavior_steal_alco()
{
    return behavior_steal_alco;
}

Behavior_to_start* Cell::get_Behavior_to_start()
{
    return behavior_to_start;
}
