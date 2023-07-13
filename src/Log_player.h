#pragma once
#include "1_Player.h"
#include "Log_print_file.h"

using namespace std;

class Log_player
{
private:
    Player_1* player;
public:
    void print_parametrs(Log_print_file* file, int way);
    void set_player(Player_1*);
};
