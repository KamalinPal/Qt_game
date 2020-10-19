#ifndef INDICANT_LIST_H
#define INDICANT_LIST_H

#include"indicant.h"

class IndicantList: Indicant
{
private:
//    int len;
//    int multiplier;
//    int offset;
public:
    IndicantList(int x);
    int getPosition() final;
    void move(int direction) final;
    void reset() final;
};

#endif // INDICANT_LIST_H
