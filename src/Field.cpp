#include "Field.h"

Field* Field::object = nullptr;

Field::Field(int x, int y) : width(x), height(y)
{
    this->ptr = new Cell* [this->width];
    for (int i = 0; i < this->width; i++)
    {
        this->ptr[i] = new Cell [this->height];
    }
}

Field::~Field()
{
    for (int i = 0; i < this->width; i++)
    {
        delete[] this->ptr[i];
    }
    delete[] this->ptr;
}

Field* Field::get_Field(int x, int y)
{
    object = new Field(x, y);
    return object;
}

void Field::In(int x, int y, bool val)
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
    {
        this->ptr[x][y].set_in(val);
    }
}

void Field::Out(int x, int y, bool val)
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
    {
        this->ptr[x][y].set_out(val);
    }
}

void Field::Unpass(int x, int y, bool val)
{
     if (x >= 0 && x < this->width && y >= 0 && y < this->height)
     {
         this->ptr[x][y].set_unpass(0);
     }
}

void Field::Player_1(int x, int y, bool val)
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
    {
        this->ptr[x][y].set_player_1(1);
    }
}

void Field::del_Player_1(int x, int y, bool val)
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
    {
        this->ptr[x][y].set_player_1(0);
    }
}

Field::Field(const Field& ref_Field)
{
    this->width = ref_Field.width;
    this->height = ref_Field.height;
    this->ptr = new Cell* [ref_Field.width];
    for (int i = 0; i < ref_Field.width; i++)
    {
        this->ptr[i] = new Cell[ref_Field.height];
        for (int j = 0; j < ref_Field.height; j++)
        {
            this->ptr[i][j] = ref_Field.ptr[i][j];
        }
    }
}

Field& Field::operator=(const Field& ref_Field)
{
    if (&ref_Field == this)
    {
        return *this;
    }

    if (this != &ref_Field){
        for (int i = 0; i < this->width; i++)
        {
            delete[] this->ptr[i];
        }
        delete[] this->ptr;
    }

    this->width = ref_Field.width;
    this->height = ref_Field.height;
    this->ptr = new Cell* [ref_Field.width];
    for (int i = 0; i < ref_Field.width; i++)
    {
        this->ptr[i] = new Cell[ref_Field.height];
        for (int j = 0; j < ref_Field.height; j++)
        {
            this->ptr[i][j] = ref_Field.ptr[i][j];
        }
    }
    return *this;
}

Field::Field(Field&& ref_Field)
{
    this->ptr = ref_Field.ptr;
    this->width = ref_Field.width;
    this->height = ref_Field.height;
    ref_Field.ptr = nullptr;
    ref_Field.width = 0;
    ref_Field.height = 0;
}

Field& Field::operator=(Field&& ref_Field)
{
    if (&ref_Field == this)
    {
        return *this;
    }

    if (this != &ref_Field){
        for (int i = 0; i < this->width; i++)
        {
            delete[] this->ptr[i];
        }
        delete[] this->ptr;
    }

    this->ptr = ref_Field.ptr;
    this->width = ref_Field.width;
    this->height = ref_Field.height;
    ref_Field.ptr = nullptr;
    ref_Field.width = 0;
    ref_Field.height = 0;
    return *this;
}
