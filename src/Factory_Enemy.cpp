#include "Factory_Enemy.h"

Element* Factory_Enemy::createElement()
{
    return new Enemy;
}
