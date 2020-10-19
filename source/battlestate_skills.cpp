#include"battlestate_skills.h"
#include"battle.h"

BattleStateSkills::BattleStateSkills()
{

}
void BattleStateSkills::go(Battle *battle)
{
    battle->useSkill();
}
bool BattleStateSkills::goBack()
{
    return true;
}
