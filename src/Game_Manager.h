#include "Field.h"
#include <SFML/Graphics.hpp>
#include "FieldIterator.h"
#include "1_Player.h"
#include "Factory_Alcogol.h"
#include "Factory_Armoor.h"
#include "Factory_Enemy.h"
#include "Factory_Medicine.h"
#include "Factory_People.h"
#include "Log_player.h"
#include "Log_print_file.h"
#include "Opponents.h"
#include "Behavior.h"
#include "Behavior_people.h"
#include "Behavior_steal_alco.h"
#include "Behavior_to_start.h"
#include "Save_file.h"
#include "Save_game.h"
#include "Load.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Game_Manager
{
public:
    void choise();

private:
    Field* field = Field::get_Field(30, 10);

    Behavior_people behavior_people;
    Behavior_steal_alco behavior_steal_alco;
    Behavior_to_start behavior_to_start;

    Player_1 man;
    Factory_People factory_people; //0 - óñëîâíûå íîìåðà äëÿ âûçîâîâ â ôóíêöèÿõ
    Factory_Alcogol factory_alcogol; //1
    Factory_Armor factory_armor; //2
    Factory_Enemy factory_enemy; //3
    Factory_Medicine factory_medicine; //4

    Log_print_file logs;
    Log_player logs_change;

    void set_Field();
    void set_Player_and_Elements_and_Logs();
    void set_Player_and_logs(int, int);
    void set_Elements_and_logs(int, int, int);
    void change_move_player(int, int);
    void change_move_player_help(int);
    void check_behavior();
    void load_game();

    void start_old_Game();
    void start_Game();
    void draw_and_move();

    void helper_1(bool, int, int, int, int, Sprite*, RenderWindow*);
    void helper_3(long long unsigned int, string, int);


    int w = 32;
    int x = 0;
    int y = 0;
};
