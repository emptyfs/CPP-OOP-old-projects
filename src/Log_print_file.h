#pragma once
#include <fstream>

using namespace std;

class Log_print_file
{
private:
    ofstream open_file;
public:
    Log_print_file();
    ~Log_print_file();
    void add_logs(string);
};
