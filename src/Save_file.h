#pragma once
#include <fstream>
#include <iostream>
#include "Open_Exp.h"

using namespace std;

class Save_file
{
private:
    ofstream save_file;
public:
    Save_file();
    ~Save_file();
    void add_info(string);
};
