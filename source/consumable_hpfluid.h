#ifndef ITEM_HEALTH_POTION_H
#define ITEM_HEALTH_POTION_H

#include"consumable.h"

class ConsumableHpFluid: public Consumable
{
public:
    ConsumableHpFluid();
    QString use(ActorPlayer *player) final;
};

#endif // ITEM_HEALTH_POTION_H
