#ifndef ITEM_MILK_H
#define ITEM_MILK_H

#include"consumable.h"
#include"item.h"

class ConsumableMilk: public Consumable
{
public:
    ConsumableMilk();
    QString use(ActorPlayer *player) final;
};

#endif // ITEM_MILK_H
