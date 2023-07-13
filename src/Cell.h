#pragma once
#include "1_Player.h"
#include "Element.h"
#include "Opponents.h"
#include "Behavior_people.h"
#include "Behavior_steal_alco.h"
#include "Behavior_to_start.h"
#include "Behavior.h"

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
    bool b1;
    bool b2;
    bool b3;

    Element* element;
    Player_1* player_11;
    Opponents<Behavior>* opponents;
    Behavior_people* behavior_people;
    Behavior_steal_alco* behavior_steal_alco;
    Behavior_to_start* behavior_to_start;

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
    void set_b1(bool);
    void set_b2(bool);
    void set_b3(bool);

    bool get_pass();
    bool get_out();
    bool get_in();
    bool get_player_1();
    bool get_people();
    bool get_alcogol();
    bool get_enemy();
    bool get_medicine();
    bool get_armor();
    bool get_b1();
    bool get_b2();
    bool get_b3();

    void set_Element(Element* elem);
    void set_Player_1(Player_1* player);
    void set_Opponents(Opponents<Behavior>* opponents);
    void set_Behavior_people(Behavior_people*);
    void set_Behavior_steal_alco(Behavior_steal_alco*);
    void set_Behavior_to_start(Behavior_to_start*);
    Element* get_Element();
    Behavior_people* get_Behavior_people();
    Behavior_steal_alco* get_Behavior_steal_alco();
    Behavior_to_start* get_Behavior_to_start();
    Opponents<Behavior>* get_Opponents();
};
