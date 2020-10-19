#ifndef BATTLE_STATE_DEFAULT_H
#define BATTLE_STATE_DEFAULT_H

#include"battlestate.h"

class BattleStateDefault: public BattleState
{
public:
    BattleStateDefault();
    void go(Battle *battle) final;
    bool goBack() final;
};

#endif // BATTLE_STATE_DEFAULT_H
