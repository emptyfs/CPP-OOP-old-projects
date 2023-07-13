#include "Log_player.h"

void Log_player::print_parametrs(Log_print_file* file, int way)
{
    switch(way)
    {
    case 0:
        file->add_logs("����� �������� �������, �� ������ =" + to_string(player->get_hp()) + "\n");
        file->add_logs("������� ���� ������� � ������� " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 1:
        file->add_logs("����� �������� �����, ����� ������ =" + to_string(player->get_armor()) + "\n");
        file->add_logs("����� ���� ������� � ������� " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 2:
        file->add_logs("����� �������� ������, ���������� �����=" + to_string(player->get_alco()) + "\n");
        file->add_logs("������ ���� ������� � ������� " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 3:
        file->add_logs("����� ������� ��, �� ������ =" + to_string(player->get_hp()) + "\n");
        file->add_logs("������ ��� ������ � ������� " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 4:
        file->add_logs("����� ���� �������, ��������� �������� =" + to_string(player->get_saved_people()) + "\n");
        file->add_logs("������ ��� ������ � ������� " + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 5:
        file->add_logs("����� ������������ �� ��������� ������� x y:" + to_string(player->get_pos_x()) + ", " + to_string(player->get_pos_y()) + "\n");
        break;
    case 6:
        file->add_logs("� ������ ������� �������, ��������� �������� =" + to_string(player->get_saved_people()) + "\n");
        break;
    case 7:
        file->add_logs("� ������ ������� ������, ���������� ����� =" + to_string(player->get_alco()) + "\n");
        break;
    case 8:
        file->add_logs("������ ����������� � ������� (0,0)\n");
    }
}

void Log_player::set_player(Player_1* player)
{
    this->player = player;
}
