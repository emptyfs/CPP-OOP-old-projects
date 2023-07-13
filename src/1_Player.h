#pragma once

#include <ostream>


class Player_1
{
private:
    int hp;
    int pos_x, pos_y;
    int armor;
    int zomb;
    int alco;
    int saved_people;

public:
    Player_1();

    void set_hp(int);
    void set_armor(int);
    void set_alco(int);
    void set_saved_people(int);

    int get_hp();
    int get_pos_x();
    int get_pos_y();
    int get_armor();
    int get_zomb();
    int get_alco();
    int get_saved_people();

    void change_place(int, int);
    void steal_hp();
    void add_hp();
    void steal_armor();
    void add_armor();
    void steal_zomb();
    void add_zomb();
    void steal_alco();
    void add_alco();
    void add_saved_people();
    void steal_people();
    void restart();
};
