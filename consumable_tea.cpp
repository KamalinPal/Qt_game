#include"consumable_tea.h"
#include"actor_player.h"

ConsumableTea::ConsumableTea()
{
    name="Tea";
    effect=1;
}

QString ConsumableTea::use(ActorPlayer *player)
{
    player->changeAttack(effect);
    return "You used "+name+". Your attack grew by "+QString::number(effect)+".\n\n";
}
