#include "Load.h"

Load::Load()
{
    try
    {
        file.open("game_saves.txt");
        if (!file.is_open())
        {
            throw Open_Exp();
        }
    }
    catch(Open_Exp)
    {
        cout << "Не удалось октрыть файл\n";
        exit(0);
    }
}

Load::~Load()
{
    file.close();
}

string Load::get_alcogol()
{
    return alcogol;
}

string Load::get_armor()
{
    return armor;
}

string Load::get_enemy()
{
    return enemy;
}

string Load::get_medicine()
{
    return medicine;
}

string Load::get_people()
{
    return people;
}

string Load::get_player()
{
    return player;
}

string Load::get_behavior_alco()
{
    return behavior_alco;
}

string Load::get_behavior_people()
{
    return behavior_people;
}

string Load::get_behavior_start()
{
    return behavior_start;
}

void Load::make_string(string line1, string line2, string* str)
{
    if (line == line1 || line == line2)
            {
                getline(file, line);
                if (*str == "000")
                {
                    *str = line;
                }
                else
                {
                    *str = (*str) + " " + line;
                }
            }
}

int Load::check()
{
    if (file.is_open())
    {
        while (getline(file, line))
        {
            icount++;
        }
        if (line == "finish" || icount == 0)
        {
            return 0;
        }
        else
        {
            cout << "Ошибка: не удалось считать файл\n";
            return 1;
        }
    }
    else
    {
        cout << "Ошибка: файл сохранения не удалось открыть\n";
        return 1;
    }
}

void Load::recover()
{
    file.close();
    file.open("game_saves.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line == "hp =" || line == "armor =" || line == "alco =" || line == "people =" || line == "pos_x(player) =" || line == "pos_y(player) =")
            {
                getline(file, line);
                player = player + line + " ";
            }
            make_string("pos_x(people) =", "pos_y(people) =", &people);
            make_string("pos_x(enemy) =", "pos_y(enemy) =", &enemy);
            make_string("pos_x(armor) =", "pos_y(armor) =", &armor);
            make_string("pos_x(medicine) =", "pos_y(medicine) =", &medicine);
            make_string("pos_x(alcogol) =", "pos_y(alcogol) =", &alcogol);
            make_string("pos_x(b1) =", "pos_y(b1) =", &behavior_people);
            make_string("pos_x(b2) =", "pos_y(b2) =", &behavior_alco);
            make_string("pos_x(b3) =", "pos_y(b3) =", &behavior_start);
        }
    }
}
