#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H

#include"actor_npc.h"
#include"shop.h"

class NpcShopkeeper: public ActorNpc
{
private:
    Shop *shop;
public:
    NpcShopkeeper();
    Shop* getShop();
};

#endif // SHOPKEEPER_H
