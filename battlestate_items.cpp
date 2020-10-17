#include"battlestate_items.h"
#include"battle.h"

BattleStateItems::BattleStateItems()
{

}
void BattleStateItems::go(Battle *battle)
{
    battle->useItem();
}
bool BattleStateItems::goBack()
{
    return true;
}
