#ifndef ITEM_MPPOTION_H
#define ITEM_MPPOTION_H

#include"consumable.h"
#include"item.h"

class ConsumableMpFluid: public Consumable
{
public:
    ConsumableMpFluid();
    QString use(ActorPlayer *player) final;
};

#endif // ITEM_MPPOTION_H
