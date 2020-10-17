#include"consumable_hpfluid.h"
#include"actor_player.h"

ConsumableHpFluid::ConsumableHpFluid()
{
    name="Hp Fluid";
    effect=4;
}
QString ConsumableHpFluid::use(ActorPlayer *player)
{
    return "You used "+name+". It restored "+QString::number(player->changeHp(effect))+" health points.\n\n";
}
