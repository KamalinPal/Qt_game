#include"equipable.h"
#include"actor_player.h"

Equipable::Equipable(int attack, int defence)
{
    equipped=false;
    this->attack=attack;
    this->defence=defence;
}
Equipable::~Equipable()
{

}
QString Equipable::use(ActorPlayer *player)
{
    if(equipped)
    {
        equipped=!equipped;
        player->changeAttack(-attack);
        player->changeDefence(-defence);
        return player->getName()+" has put "+name+" away.";
    }
    else
    {
        equipped=!equipped;
        player->changeAttack(attack);
        player->changeDefence(defence);
        return player->getName()+" equipped "+name;
    }
}
