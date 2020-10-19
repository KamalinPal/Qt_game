#ifndef ENEMY_H
#define ENEMY_H

#include"actor.h"
#include"item.h"

class ActorEnemy: public Actor
{
protected:
    Item *loot;
public:
    ActorEnemy();
    Item* getLoot();
};

#endif // ENEMY_H
