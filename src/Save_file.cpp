#include "Save_file.h"

Save_file::Save_file()
{
    try
    {
        save_file.open("C:/Users/Eldorado/Documents/qwe/oop/govno/game_saves.txt");
        if (!save_file.is_open())
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

Save_file::~Save_file()
{
    save_file.close();
}

void Save_file::add_info(string info)
{
    save_file << info;
}
