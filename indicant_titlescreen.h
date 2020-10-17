#ifndef INDICANT_TITLESCREEN_H
#define INDICANT_TITLESCREEN_H

#include"indicant.h"

class IndicantTittleScreen: public Indicant
{
public:
    IndicantTittleScreen(int x);
    int getPosition() final;
    void move(int direction) final;
    void reset() final;
};

#endif // INDICANT_TITLESCREEN_H
