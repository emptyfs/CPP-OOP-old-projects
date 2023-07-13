#include "Enemy.h"

void Enemy::operator+(Player_1& player_1)
{
    if (player_1.get_armor() == 0)
    {
        player_1.steal_hp();
    }
    else
    {
        player_1.steal_armor();
    }
}