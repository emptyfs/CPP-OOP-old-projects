#include "Save_game.h"

void Save_game::add_finish(Save_file* file)
{
    file->add_info("finish");
}

void Save_game::set_player(Player_1* player)
{
    this->player = player;
}

void Save_game::set_field(Field* field)
{
    this->field = field;
}

void Save_game::add_player(Save_file* file)
{
    file->add_info("hp =\n" + to_string(player->get_hp()) + "\n");
    file->add_info("armor =\n" + to_string(player->get_armor()) + "\n");
    file->add_info("alco =\n" + to_string(player->get_alco()) + "\n");
    file->add_info("people =\n" + to_string(player->get_saved_people()) + "\n");
    file->add_info("pos_x(player) =\n" + to_string(player->get_pos_x()) + "\n");
    file->add_info("pos_y(player) =\n" + to_string(player->get_pos_y()) + "\n");
}

void Save_game::helper(bool check, string line1, string line2, Save_file* file, int x, int y)
{
    if (check)
    {
        file->add_info(line1 + to_string(x) + "\n");
        file->add_info(line2 + to_string(y) + "\n");
    }
}

void Save_game::add_field(Save_file* file)
{
    for (int i = 0; i < field->width; i++)
        {
            for (int j = 0; j < field->height; j++)
                {
                    helper(field->ptr[i][j].get_people(), "pos_x(people) =\n", "pos_y(people) =\n", file, i, j);
                    helper(field->ptr[i][j].get_enemy(), "pos_x(enemy) =\n", "pos_y(enemy) =\n", file, i, j);
                    helper(field->ptr[i][j].get_medicine(), "pos_x(medicine) =\n", "pos_y(medicine) =\n", file, i, j);
                    helper(field->ptr[i][j].get_armor(), "pos_x(armor) =\n", "pos_y(armor) =\n", file, i, j);
                    helper(field->ptr[i][j].get_alcogol(), "pos_x(alcogol) =\n", "pos_y(alcogol) =\n", file, i, j);
                    helper(field->ptr[i][j].get_b1(), "pos_x(b1) =\n", "pos_y(b1) =\n", file, i, j);
                    helper(field->ptr[i][j].get_b2(), "pos_x(b2) =\n", "pos_y(b2) =\n", file, i, j);
                    helper(field->ptr[i][j].get_b3(), "pos_x(b3) =\n", "pos_y(b3) =\n", file, i, j);
                }
        }
}
