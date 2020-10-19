#include"skill_fireball.h"
#include"actor_enemy.h"
#include"actor_player.h"

SkillFireball::SkillFireball()
{
    cost=3;
    effect=6;
    name="Fireball";
//    pixmap=QPixmap(":/images/skills.png").copy(0, 0, 24, 24);
}
QString SkillFireball::use(ActorPlayer *player, ActorEnemy *enemy)
{
    if(!enemy) return "No enemy.";
    if(player->getMp()>=cost)
    {
        player->changeMp(-cost);
        return "You used "+name+". It dealt "+QString::number(enemy->changeHp(-effect))+" damage.\n\n";
    }
    return "Not enough Mana Points.\n\n";
}
