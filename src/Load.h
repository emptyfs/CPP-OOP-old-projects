#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Open_Exp.h"

using namespace std;

class Load
{
private:
    int icount;
    ifstream file;
    string line;
    string player;
    string people = "000";
    string armor = "000";
    string enemy = "000";
    string alcogol = "000";
    string medicine = "000";
    string behavior_people = "000";
    string behavior_alco = "000";
    string behavior_start = "000";

public:
    Load();
    ~Load();

    int check();
    void recover();
    string get_player();
    string get_people();
    string get_armor();
    string get_enemy();
    string get_alcogol();
    string get_medicine();
    string get_behavior_people();
    string get_behavior_alco();
    string get_behavior_start();

    void make_string(string, string, string*);
};
