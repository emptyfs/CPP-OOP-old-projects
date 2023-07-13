#include "Log_print_file.h"

Log_print_file::Log_print_file()
{
    open_file.open("C:/Users/Eldorado/Documents/qwe/oop/govno/game_logs.txt");
    open_file << "logs:\n";
}

Log_print_file::~Log_print_file()
{
    open_file.close();
}

void Log_print_file::add_logs(string log)
{
    open_file << "log: " << log << "\n";
}

