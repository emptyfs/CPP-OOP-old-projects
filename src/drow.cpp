#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>
#include "FieldIterator.h"
#include "1_Player.h"
#include "Factory_Alcogol.h"
#include "Factory_Armoor.h"
#include "Factory_Enemy.h"
#include "Factory_Medicine.h"
#include "Factory_People.h"

using namespace sf;

class drow
{
private:
    int x = 0;
    int y = 0;
    int w = 32;

public:
    void show(Field* field)
    {
        RenderWindow app(VideoMode(32 * field->width, 32 * (field->height+2)), "Cool game :)");

        Texture t;
        //t.loadFromFile("C:/Users/Eldorado/Documents/qwe/oop/govno/titles.jpg");
        t.loadFromFile("C:/Users/Eldorado/Documents/qwe/oop/govno/fantasy-tileset.png");
        Sprite s(t);
        Player_1 man;
        field->ptr[0][0].set_Player_1(&man);
        Font font;
        font.loadFromFile("19849.ttf");
        Text Player_1_info;
        Player_1_info.setFont(font);
        Player_1_info.setCharacterSize(20);
        Player_1_info.setColor(Color::Red);
        Player_1_info.setStyle(Text::Bold);
        Player_1_info.setPosition(Vector2f(0,(field->height)*32));

        Factory_People factory_people;
        Factory_Alcogol factory_alcogol;
        Factory_Armor factory_armor;
        Factory_Enemy factory_enemy;
        Factory_Medicine factory_medicine;

        field->ptr[3][1].set_Element(factory_people.createElement());
        field->ptr[3][1].set_people(1);
        field->ptr[28][1].set_Element(factory_people.createElement());
        field->ptr[28][1].set_people(1);
        field->ptr[1][8].set_Element(factory_people.createElement());
        field->ptr[1][8].set_people(1);
        field->ptr[6][3].set_Element(factory_enemy.createElement());
        field->ptr[6][3].set_enemy(1);
        field->ptr[3][8].set_Element(factory_enemy.createElement());
        field->ptr[3][8].set_enemy(1);
        field->ptr[7][5].set_Element(factory_enemy.createElement());
        field->ptr[7][5].set_enemy(1);
        field->ptr[1][5].set_Element(factory_medicine.createElement());
        field->ptr[1][5].set_medicine(1);
        field->ptr[9][3].set_Element(factory_medicine.createElement());
        field->ptr[9][3].set_medicine(1);
        field->ptr[7][7].set_Element(factory_armor.createElement());
        field->ptr[7][7].set_armor(1);
        field->ptr[10][5].set_Element(factory_armor.createElement());
        field->ptr[10][5].set_armor(1);
        field->ptr[28][3].set_Element(factory_alcogol.createElement());
        field->ptr[28][3].set_alcogol(1);




        while (app.isOpen())
        {
            app.clear();
            for (int i = 0; i < field->width; i++)
            {
                for (int j = 0; j < field->height; j++)
                    {
                        if (!field->ptr[i][j].get_in() && !field->ptr[i][j].get_out() && field->ptr[i][j].get_pass())
                        {
                            s.setTextureRect(IntRect(0, 1 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                            //ïðîõîäèìàÿ
                        }
                        if (field->ptr[i][j].get_in())
                        {
                            s.setTextureRect(IntRect(5 * w, 1 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                            //âõîä
                        }
                        if (field->ptr[i][j].get_out())
                        {
                            s.setTextureRect(IntRect(1 * w, 3 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                            //âûõîä
                        }
                        if (!field->ptr[i][j].get_pass())
                        {
                            s.setTextureRect(IntRect(0 * w, 3 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                            //íåïðîõîäèìàÿ
                        }
                        if (field->ptr[i][j].get_player_1())
                        {
                            s.setTextureRect(IntRect(5 * w, 18 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                        if (field->ptr[i][j].get_people())
                        {
                            s.setTextureRect(IntRect(1 * w, 20 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                        if (field->ptr[i][j].get_enemy())
                        {
                            s.setTextureRect(IntRect(0 * w, 18 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                        if (field->ptr[i][j].get_medicine())
                        {
                            s.setTextureRect(IntRect(0 * w, 20 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                        if (field->ptr[i][j].get_armor())
                        {
                            s.setTextureRect(IntRect(7 * w, 13 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                        if (field->ptr[i][j].get_alcogol())
                        {
                            s.setTextureRect(IntRect(6 * w, 5 * w, w, w));
                            s.setPosition(i*w, j*w);
                            app.draw(s);
                        }
                    }
            }




            if (man.get_hp() == 0)
            {
                Player_1_info.setString("Game over");
                app.draw(Player_1_info);
            }
            else if (man.get_saved_people() == 3 && x == field->width-1 && y == field->height-1)
            {
                Player_1_info.setString("Victory");
                app.draw(Player_1_info);
            }
            else
            {
                Player_1_info.setString("Hp: " + std::to_string(man.get_hp()) + "\tarmor: " + std::to_string(man.get_armor()) + "\tsaved poeple: " + std::to_string(man.get_saved_people()) + "\talco: " + std::to_string(man.get_alco()));
                app.draw(Player_1_info);
            }
            Event e;

            while(app.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    app.close();
                if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Escape) app.close();
                    if (e.key.code == Keyboard::Left)
                    {
                        if ((x-1) >= 0)
                        {
                            if (field->ptr[x-1][y].get_pass())
                            {
                                x--;
                                man.change_place(x, y);
                                field->ptr[x][y].set_Player_1(&man);
                                field->ptr[x+1][y].delete_Player_1();
                                field->Player_1(x,y,1);
                                field->del_Player_1(x+1,y,0);
                                if (field->ptr[x][y].get_people())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_people(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_enemy())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_enemy(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_medicine())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_medicine(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_armor())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_armor(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_alcogol())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_alcogol(0);
                                    field->ptr[x][y].delete_Element();
                                }
                            }
                        }
                    }
                    if (e.key.code == Keyboard::Right)
                    {
                        if ((x+1) < field->width)
                        {
                            if (field->ptr[x+1][y].get_pass())
                            {
                                x++;
                                man.change_place(x, y);
                                field->ptr[x][y].set_Player_1(&man);
                                field->ptr[x-1][y].delete_Player_1();
                                field->Player_1(x,y,1);
                                field->del_Player_1(x-1,y,0);
                                if (field->ptr[x][y].get_people())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_people(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_enemy())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_enemy(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_medicine())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_medicine(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_armor())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_armor(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_alcogol())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_alcogol(0);
                                    field->ptr[x][y].delete_Element();
                                }
                            }
                        }
                    }
                    if (e.key.code == Keyboard::Up)
                    {
                        if ((y-1) >= 0)
                        {
                            if (field->ptr[x][y-1].get_pass())
                            {
                                y--;
                                man.change_place(x, y);
                                field->ptr[x][y].set_Player_1(&man);
                                field->ptr[x][y+1].delete_Player_1();
                                field->Player_1(x,y,1);
                                field->del_Player_1(x,y+1,0);
                                if (field->ptr[x][y].get_people())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_people(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_enemy())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_enemy(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_medicine())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_medicine(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_armor())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_armor(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_alcogol())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_alcogol(0);
                                    field->ptr[x][y].delete_Element();
                                }
                            }
                        }
                    }
                    if (e.key.code == Keyboard::Down)
                    {
                        if ((y+1) < field->height)
                        {
                            if (field->ptr[x][y+1].get_pass())
                            {
                                y++;
                                man.change_place(x, y);
                                field->ptr[x][y].set_Player_1(&man);
                                field->ptr[x][y-1].delete_Player_1();
                                field->Player_1(x,y,1);
                                field->del_Player_1(x,y-1,0);
                                if (field->ptr[x][y].get_people())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_people(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_enemy())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_enemy(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_medicine())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_medicine(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_armor())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_armor(0);
                                    field->ptr[x][y].delete_Element();
                                }
                                if (field->ptr[x][y].get_alcogol())
                                {
                                    *(field->ptr[x][y].get_Element()) + man;
                                    field->ptr[x][y].set_alcogol(0);
                                    field->ptr[x][y].delete_Element();
                                }
                            }
                        }
                    }
                }
            }
            app.display();
        }
    }
};
