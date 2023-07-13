#pragma once
#include "1_Player.h"
#include "Element.h"

class Cell
{
private:
    bool pass;
    bool out;
    bool in;
    bool player_1;
    bool people;
    bool alcogol;
    bool enemy;
    bool medicine;
    bool armor;

    Element* element;
    Player_1* player_11;

public:
    Cell();
    ~Cell();

    void set_unpass(bool value);
    void set_out(bool value);
    void set_in(bool value);
    void set_player_1(bool value);
    void set_people(bool value);
    void set_alcogol(bool value);
    void set_enemy(bool value);
    void set_medicine(bool value);
    void set_armor(bool value);

    bool get_pass();
    bool get_out();
    bool get_in();
    bool get_player_1();
    bool get_people();
    bool get_alcogol();
    bool get_enemy();
    bool get_medicine();
    bool get_armor();

    void set_Element(Element* elem);
    void set_Player_1(Player_1* player);
    void delete_Element();
    void delete_Player_1();
    Element* get_Element();
};
