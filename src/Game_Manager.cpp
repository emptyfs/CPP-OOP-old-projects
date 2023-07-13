#include "Game_Manager.h"

using namespace sf;
using namespace std;

void Game_Manager::choise()
{
    int way;
    cout << "×òîáû íà÷àòü íîâóþ èãðó ââåäèòå '0', ÷òîáû íà÷àòü ñòàðóþ èãðó ââåäèòå '1'\n";
    cin >> way;

    if (way == 0)
    {
        start_Game();
    }
    else if (way == 1)
    {
        start_old_Game();
    }
    else
    {
        cout << "Âû ââåëè íåâåðíûé ñèìâîë\n";
    }
}

void Game_Manager::start_old_Game()
{
    set_Field();
    load_game();
    draw_and_move();
}

void Game_Manager::start_Game()
{
    set_Field();
    set_Player_and_Elements_and_Logs();
    draw_and_move();
}

void Game_Manager::helper_3(long long unsigned int len, string str, int flag)
{
    if (str != "000")
    {
        long long unsigned int icount = 0;
        while (icount < len)
        {
            int x = icount;
            int y = icount + 2;
            set_Elements_and_logs(atoi(&str[x]), atoi(&str[y]), flag);
            icount = icount + 4;
        }
    }
}

void Game_Manager::load_game()
{
    Load load;
    if (load.check() == 1)
    {
        return;
    };
    load.recover();
    man.set_hp(atoi(&load.get_player()[0]));
    man.set_armor(atoi(&load.get_player()[2]));
    man.set_alco(atoi(&load.get_player()[4]));
    man.set_saved_people(atoi(&load.get_player()[6]));
    man.change_place(atoi(&load.get_player()[8]), atoi(&load.get_player()[10]));
    x = man.get_pos_x();
    y = man.get_pos_y();
    set_Player_and_logs(x, y);
    /*cout << load.get_people() << "\n";
    cout << load.get_alcogol() << "\n";
    cout << load.get_armor() << "\n";
    cout << load.get_enemy() << "\n";
    cout << load.get_medicine() << "\n";
    cout << load.get_behavior_people() << "\n";
    cout << load.get_behavior_alco() << "\n";
    cout << load.get_behavior_start() << "\n";*/
    helper_3(load.get_people().length(), load.get_people(), 0);
    helper_3(load.get_alcogol().length(), load.get_alcogol(), 4);
    helper_3(load.get_armor().length(), load.get_armor(), 3);
    helper_3(load.get_enemy().length(), load.get_enemy(), 1);
    helper_3(load.get_medicine().length(), load.get_medicine(), 2);
    helper_3(load.get_behavior_alco().length(), load.get_behavior_alco(), 6);
    helper_3(load.get_behavior_people().length(), load.get_behavior_people(), 5);
    helper_3(load.get_behavior_start().length(), load.get_behavior_start(), 7);
}

void Game_Manager::helper_1(bool check, int x, int y, int cor1, int cor2, Sprite* s, RenderWindow* app)
{
    if (check)
    {
        s->setTextureRect(IntRect(cor1 * w, cor2 * w, w, w));
        s->setPosition(x*w, y*w);
        app->draw(*s);
    }
}

void Game_Manager::draw_and_move()
{
    RenderWindow app(VideoMode(32 * field->width, 32 * (field->height+2)), "Cool game :)");
    Texture t;
    Sprite s(t);
    Font font;
    Text Player_1_info;
    t.loadFromFile("C:/Users/Eldorado/Documents/qwe/oop/govno/fantasy-tileset.png");
    font.loadFromFile("19849.ttf");
    Player_1_info.setFont(font);
    Player_1_info.setCharacterSize(20);
    Player_1_info.setFillColor(Color::Red);
    Player_1_info.setStyle(Text::Bold);
    Player_1_info.setPosition(Vector2f(0,(field->height)*32));

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
                    helper_1(field->ptr[i][j].get_in(), i, j, 5, 1, &s, &app);
                    helper_1(field->ptr[i][j].get_out(), i, j, 1, 3, &s, &app);
                    helper_1(!field->ptr[i][j].get_pass(), i, j, 0, 3, &s, &app);
                    helper_1(field->ptr[i][j].get_player_1(), i, j, 5, 18, &s, &app);
                    helper_1(field->ptr[i][j].get_people(), i, j, 1, 20, &s, &app);
                    helper_1(field->ptr[i][j].get_enemy(), i, j, 0, 18, &s, &app);
                    helper_1(field->ptr[i][j].get_medicine(), i, j, 0, 20, &s, &app);
                    helper_1(field->ptr[i][j].get_armor(), i, j, 7, 13, &s, &app);
                    helper_1(field->ptr[i][j].get_alcogol(), i, j, 6, 5, &s, &app);
                    if (field->ptr[i][j].get_b1() || field->ptr[i][j].get_b2() || field->ptr[i][j].get_b3())
                    {
                        s.setTextureRect(IntRect(7 * w, 18 * w, w, w));
                        s.setPosition(i*w, j*w);
                        app.draw(s);

                    }
                    if (field->ptr[i][j].get_b1() || field->ptr[i][j].get_b2() || field->ptr[i][j].get_b3())
                    {
                        s.setTextureRect(IntRect(7 * w, 18 * w, w, w));
                        s.setPosition(i*w, j*w);
                        app.draw(s);

                    }
                }
        }

        if (man.get_hp() == 0)
        {
            Player_1_info.setString("Game over\nYou saved " + std::to_string(man.get_saved_people()) + " rabbits");
            app.draw(Player_1_info);
        }
        else if (man.get_saved_people() == 3 && x == field->width-1 && y == field->height-1)
        {
            Player_1_info.setString("Victory\nYou saved everyone");
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
                            change_move_player(-1, 0);
                        }
                    }
                }
                if (e.key.code == Keyboard::Right)
                {
                    if ((x+1) < field->width)
                    {
                        if (field->ptr[x+1][y].get_pass())
                        {
                            change_move_player(1, 0);
                        }
                    }
                }
                if (e.key.code == Keyboard::Up)
                {
                    if ((y-1) >= 0)
                    {
                        if (field->ptr[x][y-1].get_pass())
                        {
                            change_move_player(0, -1);
                        }
                    }
                }
                if (e.key.code == Keyboard::Down)
                {
                    if ((y+1) < field->height)
                    {
                        if (field->ptr[x][y+1].get_pass())
                        {
                            change_move_player(0, 1);
                        }
                    }
                }

                if (e.key.code == Keyboard::O)
                {
                    Save_file saved_file;
                    Save_game saved_game;
                    saved_game.set_player(&man);
                    saved_game.set_field(field);
                    saved_game.add_player(&saved_file);
                    saved_game.add_field(&saved_file);
                    saved_game.add_finish(&saved_file);
                }
                if (e.key.code == Keyboard::P)
                {
                    load_game();
                }
            }
        }
        app.display();
    }
}

void Game_Manager::change_move_player_help(int way)
{
    *(field->ptr[x][y].get_Element()) + man;
    switch(way)
    {
    case 0:
        field->ptr[x][y].set_people(0);
        logs_change.print_parametrs(&logs, 4);
        break;
    case 1:
        field->ptr[x][y].set_enemy(0);
        logs_change.print_parametrs(&logs, 3);
        break;
    case 2:
        field->ptr[x][y].set_medicine(0);
        logs_change.print_parametrs(&logs, 0);
        break;
    case 3:
        field->ptr[x][y].set_armor(0);
        logs_change.print_parametrs(&logs, 1);
        break;
    case 4:
        field->ptr[x][y].set_alcogol(0);
        logs_change.print_parametrs(&logs, 2);
        break;
    }
}

void Game_Manager::change_move_player(int x_change, int y_change)
{
    x = x + x_change;
    y = y + y_change;
    man.change_place(x, y);
    field->ptr[x][y].set_Player_1(&man);
    field->Player_1(x,y,1);
    field->del_Player_1(x-x_change,y-y_change,0);
    logs_change.print_parametrs(&logs, 5);
    if (field->ptr[x][y].get_people())
    {
        change_move_player_help(0);
    }
    if (field->ptr[x][y].get_enemy())
    {
        change_move_player_help(1);
    }
    if (field->ptr[x][y].get_medicine())
    {
        change_move_player_help(2);
    }
    if (field->ptr[x][y].get_armor())
    {
        change_move_player_help(3);
    }
    if (field->ptr[x][y].get_alcogol())
    {
        change_move_player_help(4);
    }
    if (field->ptr[x][y].get_b1() || field->ptr[x][y].get_b2() || field->ptr[x][y].get_b3())
    {
        check_behavior();
    }
}

void Game_Manager::check_behavior()
{
    if (field->ptr[x][y].get_b1())
    {
        field->ptr[x][y].set_b1(0);
        *(field->ptr[x][y].get_Behavior_people()) - man;
        logs_change.print_parametrs(&logs, 6);
    }
    if (field->ptr[x][y].get_b3())
    {
        field->ptr[x][y].set_b3(0);
        *(field->ptr[x][y].get_Behavior_to_start()) - man;
        field->del_Player_1(x,y,0);
        field->ptr[x][y].set_player_1(0);
        x = man.get_pos_x();
        y = man.get_pos_y();
        field->ptr[x][y].set_player_1(1);
        logs_change.print_parametrs(&logs, 8);
    }
    if (field->ptr[x][y].get_b2())
    {
        field->ptr[x][y].set_b2(0);
        *(field->ptr[x][y].get_Behavior_steal_alco()) - man;
        logs_change.print_parametrs(&logs, 7);
    }
}

void Game_Manager::set_Field()
{
    for (int i = 2; i < 30; i++)
    {
        field->Unpass(i, 0, 0);
    }
    for (int i = 0; i < 8; i++)
    {
        field->Unpass(29, i, 0);
    }
    for (int i = 1; i < 10; i++)
    {
        field->Unpass(0, i, 0);
    }
    for (int i = 1; i < 29; i++)
    {
        field->Unpass(i, 9, 0);
    }
	field->In(0,0,1);
	field->Out(29,9,1);
	field->Unpass(7,2,0);
	field->Unpass(7,3,0);
	field->Unpass(7,4,0);
	field->Unpass(4,5,0);
	field->Unpass(4,6,0);
	field->Unpass(4,7,0);
	field->Unpass(4,8,0);
	field->Unpass(2,6,0);
	field->Unpass(2,7,0);
	field->Unpass(6,6,0);
	field->Unpass(6,7,0);
	field->Unpass(1,4,0);
	field->Unpass(4,7,0);
	for (int i = 9; i < 29; i++)
    {
        field->Unpass(i, 2, 0);
    }
    field->Unpass(10,6,0);
    for (int i = 11; i < 28; i++)
    {
        field->Unpass(i, 6, 0);
    }
    field->Unpass(10,3,0);
    field->Unpass(10,4,0);
    field->Unpass(9,4,0);
    field->Unpass(9,5,0);
    field->Unpass(9,6,0);
	field->Unpass(4,8,0);
	field->Unpass(2,4,0);
	field->Unpass(4,4,0);
	field->Unpass(6,5,0);
	field->Unpass(2,0,0);
	field->Unpass(2,1,0);
	field->Unpass(2,2,0);
	field->Unpass(3,2,0);
	field->Unpass(4,2,0);
	field->Unpass(5,2,0);
	field->Unpass(6,2,0);
	field->Unpass(6,4,0);
}

void Game_Manager::set_Player_and_logs(int x, int y)
{
    field->ptr[x][y].set_Player_1(&man);
    field->Player_1(x,y
                    ,1);
    logs_change.set_player(&man);
    logs.add_logs("Èãðîê óñòàíîâëåí â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
}

void Game_Manager::set_Elements_and_logs(int x, int y, int log)
{
    switch(log)
    {
    case 0:
        field->ptr[x][y].set_Element(factory_people.createElement());
        factory_people.set_xy(x, y);
        field->ptr[x][y].set_people(1);
        logs.add_logs("Êðîëèêè óñòàíîâëåíû â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 1:
        field->ptr[x][y].set_Element(factory_enemy.createElement());
        factory_enemy.set_xy(x, y);
        field->ptr[x][y].set_enemy(1);
        logs.add_logs("Ãîáëèíû óñòàíîâëåíû â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 2:
        field->ptr[x][y].set_Element(factory_medicine.createElement());
        factory_medicine.set_xy(x, y);
        field->ptr[x][y].set_medicine(1);
        logs.add_logs("Àïòå÷êè óñòàíîâëåíû â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 3:
        field->ptr[x][y].set_Element(factory_armor.createElement());
        factory_armor.set_xy(x, y);
        field->ptr[x][y].set_armor(1);
        logs.add_logs("Áðîíÿ óñòàíîâëåíà â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 4:
        field->ptr[x][y].set_Element(factory_alcogol.createElement());
        factory_alcogol.set_xy(x, y);
        field->ptr[x][y].set_alcogol(1);
        logs.add_logs("Áóòûëü óñòàíîâëåíà â: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 5:
        field->ptr[x][y].set_Behavior_people(&behavior_people);
        behavior_people.set_xy(x, y);
        field->ptr[x][y].set_b1(1);
        logs.add_logs("Âðàãó óñòàíîâëåíî ïîâåäåíèå b1 (êðàæà êðîëèêà) â ïîçèöèè: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 6:
        field->ptr[x][y].set_Behavior_steal_alco(&behavior_steal_alco);
        behavior_steal_alco.set_xy(x, y);
        field->ptr[x][y].set_b2(1);
        logs.add_logs("Âðàãó óñòàíîâëåíî ïîâåäåíèå b2 (êðàæà áóòûëè) â ïîçèöèè: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    case 7:
        field->ptr[x][y].set_Behavior_to_start(&behavior_to_start);
        behavior_to_start.set_xy(x, y);
        field->ptr[x][y].set_b3(1);
        logs.add_logs("Âðàãó óñòàíîâëåíî ïîâåäåíèå b3 (îòïðàâêà â íà÷àëî) â ïîçèöèè: " + std::to_string(x) + ", " + std::to_string(y) + "\n");
        break;
    }
}

void Game_Manager::set_Player_and_Elements_and_Logs()
{
    set_Player_and_logs(0, 0);
    set_Elements_and_logs(3, 1, 0);
    set_Elements_and_logs(28, 1, 0);
    set_Elements_and_logs(1, 8, 0);
    set_Elements_and_logs(6, 3, 1);
    set_Elements_and_logs(3, 8, 1);
    set_Elements_and_logs(7, 5, 1);
    set_Elements_and_logs(1, 5, 2);
    set_Elements_and_logs(9, 3, 2);
    set_Elements_and_logs(7, 7, 3);
    set_Elements_and_logs(10, 5, 3);
    set_Elements_and_logs(28, 3, 4);
    set_Elements_and_logs(9, 7, 5);
    set_Elements_and_logs(10, 7, 6);
    set_Elements_and_logs(11, 7, 7);
}
