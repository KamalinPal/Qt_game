#ifndef INDICANT_BATTLE_H
#define INDICANT_BATTLE_H

#include"indicant.h"

class IndicantBattle: public Indicant
{
public:
    IndicantBattle(int x);
    void move(int direction) final;
    void reset() final;
};

#endif // INDICANT_BATTLE_H
