#include"consumable_mpfluid.h"
#include"actor_player.h"

ConsumableMpFluid::ConsumableMpFluid()
{
    name="Mp Fluid";
    effect=2;
}

QString ConsumableMpFluid::use(ActorPlayer *player)
{
    return "You used "+name+". It restored "+QString::number(player->changeMp(effect))+" mana points.\n\n";
}
