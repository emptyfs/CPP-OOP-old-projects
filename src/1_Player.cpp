#include "1_Player.h"

Player_1::Player_1()
{
    this->hp = 3;
    this->pos_x = 0;
    this->pos_y = 0;
    this->armor = 0;
    this->zomb = 0;
    this->alco = 0;
    this->saved_people = 0;
}

void Player_1::set_hp(int hp)
{
    this->hp = hp;
}

void Player_1::set_armor(int armor)
{
    this->armor = armor;
}

void Player_1::set_alco(int alco)
{
    this->alco = alco;
}

void Player_1::set_saved_people(int saved_people)
{
    this->saved_people = saved_people;
}

void Player_1::restart()
{
    this->hp = 3;
    this->pos_x = 0;
    this->pos_y = 0;
    this->armor = 0;
    this->zomb = 0;
    this->alco = 0;
    this->saved_people = 0;
}

int Player_1::get_hp()
{
    return this->hp;
}

int Player_1::get_pos_x()
{
    return this->pos_x;
}

int Player_1::get_pos_y()
{
    return this->pos_y;
}

int Player_1::get_armor()
{
    return this->armor;
}

int Player_1::get_zomb()
{
    return this->zomb;
}

int Player_1::get_alco()
{
    return this->alco;
}

int Player_1::get_saved_people()
{
    return this->saved_people;
}

void Player_1::change_place(int x, int y)
{
    this->pos_x = x;
    this->pos_y = y;
}

void Player_1::steal_hp()
{
    if (this->hp > 0)
    {
        this->hp--;
    }
}

void Player_1::add_hp()
{
    if (this->hp < 3)
    {
        this->hp++;
    }
}

void Player_1::steal_armor()
{
    if (this->armor > 0)
    {
        this->armor--;
    }
}

void Player_1::add_armor()
{
    if (this->armor < 3)
    {
        this->armor++;
    }
}

void Player_1::steal_zomb()
{
    if (this->zomb > 0)
    {
        this->zomb--;
    }
}

void Player_1::add_zomb()
{
    if (this->zomb < 5)
    {
        this->zomb++;
    }
}

void Player_1::steal_alco()
{
    if (this->alco > 0)
    {
        this->alco--;
    }
}

void Player_1::steal_people()
{
    if (this->saved_people > 0)
    {
        this->saved_people--;
    }
}

void Player_1::add_alco()
{
    if (this->alco < 3)
    {
        this->alco++;
    }
}

void Player_1::add_saved_people()
{
    if (this->saved_people < 3)
    {
        this->saved_people++;
    }
}
