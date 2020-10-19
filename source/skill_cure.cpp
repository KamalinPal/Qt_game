#include"skill_cure.h"
#include"actor_enemy.h"
#include"actor_player.h"

SkillCure::SkillCure()
{
    name="Cure";
    effect=10;
    cost=5;
}
QString SkillCure::use(ActorPlayer *player, ActorEnemy *)
{
    if(player->getMp()>=cost)
    {
        player->changeMp(-cost);
        return "You used "+name+". It restored "+QString::number(player->changeHp(effect))+" health points.\n\n";
    }
    return "Not enough Mana Points.\n\n";
}
