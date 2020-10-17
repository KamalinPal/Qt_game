#include"skill_frost.h"
#include"actor_enemy.h"
#include"actor_player.h"
#include<QtDebug>

SkillFrost::SkillFrost()
{
    name="Frost";
    effect=2;
    cost=1;
}
QString SkillFrost::use(ActorPlayer *player, ActorEnemy *enemy)
{
    if(!enemy) return "No enemy.";
    if(player->getMp()>=cost)
    {
        player->changeMp(-cost);
        return "You used "+name+". It dealt "+QString::number(enemy->changeHp(-effect))+" damage.\n\n";
    }
    return "Not enough Mana Points.\n\n";
}
