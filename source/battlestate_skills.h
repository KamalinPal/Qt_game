#ifndef BATTLE_STATE_SKILLS_H
#define BATTLE_STATE_SKILLS_H

#include"battlestate.h"

class BattleStateSkills: public BattleState
{
public:
    BattleStateSkills();
    void go(Battle *battle) final;
    bool goBack() final;
};

#endif // BATTLE_STATE_SKILLS_H
