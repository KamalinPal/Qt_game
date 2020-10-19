#ifndef BATTLE_STATE_ITEMS_H
#define BATTLE_STATE_ITEMS_H

#include"battlestate.h"

class BattleStateItems: public BattleState
{
public:
    BattleStateItems();
    void go(Battle *battle) final;
    bool goBack() final;
};

#endif // BATTLE_STATE_ITEMS_H
