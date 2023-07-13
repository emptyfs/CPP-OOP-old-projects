#pragma once
#include "1_Player.h"
#include "Save_file.h"
#include "Field.h"
#include <string>

using namespace std;

class Save_game
{
private:
    Player_1* player;
    Field* field;

    void helper(bool, string, string, Save_file*, int, int);

public:
    void set_player(Player_1*);
    void set_field(Field*);

    void add_player(Save_file*);
    void add_field(Save_file*);
    void add_finish(Save_file*);
};
