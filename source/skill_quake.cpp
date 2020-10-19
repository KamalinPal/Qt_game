#include"skill_quake.h"
#include"actor_enemy.h"
#include"actor_player.h"

SkillQuake::SkillQuake()
{
    name="Quake";
    effect=14;
    cost=7;
}
QString SkillQuake::use(ActorPlayer *player, ActorEnemy *enemy)
{
    if(!enemy) return "No enemy.";
    if(player->getMp()>=cost)
    {
        player->changeMp(-cost);
        return "You used "+name+". It dealt "+QString::number(enemy->changeHp(-effect))+" damage.\n\n";
    }
    return "Not enough Mana Points.\n\n";
}
