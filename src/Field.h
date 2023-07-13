#pragma once
#include "Cell.h"
#include "1_Player.h"

class Field
{
private:
    Cell** ptr = nullptr;
    int width, height;
    static Field* object;

    Field(int width, int height);
    ~Field();
    Field(const Field& ref_Field);
    Field& operator=(const Field& ref_Field);
    Field(Field&& ref_Field);
    Field& operator=(Field&& ref_Field);

public:
    static Field* get_Field(int x, int y);
    void In(int x, int y, bool val);
    void Out(int x, int y, bool val);
    void Unpass(int x, int y, bool val);
    void Player_1(int x, int y, bool val);
    void del_Player_1(int x, int y, bool val);

friend class Game_Manager;
friend class Iterator;
friend class Save_game;
};
