#include "Log_player.h"

void Log_player::print_parametrs(Log_print_file* file, int way)
{
    switch(way)
    {
    case 0:
        file->add_logs("Игрок подобрал аптечку, хп игрока =" + to_string(player->get_hp()) + "\n");
        file->add_logs("Аптечка была удалена с позиции " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 1:
        file->add_logs("Игрок подобрал броню, броня игрока =" + to_string(player->get_armor()) + "\n");
        file->add_logs("Броня была удалена с позиции " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 2:
        file->add_logs("Игрок подобрал бутыль, количество зелей=" + to_string(player->get_alco()) + "\n");
        file->add_logs("Бутыль была удалена с позиции " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 3:
        file->add_logs("Игрок потерял хп, хп игрока =" + to_string(player->get_hp()) + "\n");
        file->add_logs("Гоблин был удален с позиции " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 4:
        file->add_logs("Игрок спас кролика, спасенных кроликов =" + to_string(player->get_saved_people()) + "\n");
        file->add_logs("Кролик был удален с позиции " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 5:
        file->add_logs("Игрок передвинулся на следующие позиции x y:" + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 6:
        file->add_logs("У игрока забрали кролика, спасенных кроликов =" + to_string(player->get_saved_people()) + "\n");
        break;
    case 7:
        file->add_logs("У игрока забрали бутыль, количество зелей =" + to_string(player->get_alco()) + "\n");
        break;
    case 8:
        file->add_logs("Игрока передвинули в позицию (0,0)\n");
    }
}

void Log_player::set_player(Player_1* player)
{
    this->player = player;
}
