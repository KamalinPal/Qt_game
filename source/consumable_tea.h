#ifndef ITEM_TEA_H
#define ITEM_TEA_H

#include"consumable.h"
#include"item.h"

class ConsumableTea: public Consumable
{
public:
    ConsumableTea();
    QString use(ActorPlayer *player) final;
};

#endif // ITEM_TEA_H
