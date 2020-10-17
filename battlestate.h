#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

class Battle;

class BattleState
{
public:
    BattleState();
    virtual ~BattleState();
    virtual void go(Battle *battle)=0;
    virtual bool goBack()=0;
};

#endif // BATTLE_STATE_H
