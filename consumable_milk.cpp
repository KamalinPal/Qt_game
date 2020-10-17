#include"consumable_milk.h"
#include"actor_player.h"

ConsumableMilk::ConsumableMilk()
{
    name="Milk";
    effect=1;
}

QString ConsumableMilk::use(ActorPlayer *player)
{
    player->changeDefence(effect);
    return "You used "+name+". Your defence grew by "+QString::number(effect)+".\n\n";
}
