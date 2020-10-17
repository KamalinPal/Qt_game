#include"actor_enemy.h"
#include"item_bone.h"

ActorEnemy::ActorEnemy()
{
    sheet=QPixmap(":/images/death.png");
    setPixmap(sheet.copy(0, 0, 32, 48));
    name="Enemy";
    hp=4;
    attack=1;
    defence=0;
    exp=2;
    loot=new ItemBone();
}
Item *ActorEnemy::getLoot()
{
    return loot;
}
