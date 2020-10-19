#include"battlestate_default.h"
#include"battle.h"
#include<QtDebug>

BattleStateDefault::BattleStateDefault()
{

}
void BattleStateDefault::go(Battle *battle)
{
    switch(battle->getIndicant()->getPosition())
    {
    case 0: battle->attack(); break;
    case 1: battle->goItems(); break;
    case 2: battle->goSkills(); break;
    case 3: battle->flee(); break;
    }
}
bool BattleStateDefault::goBack()
{
    return false;
}
