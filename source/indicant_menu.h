#ifndef INDICANT_MENU_H
#define INDICANT_MENU_H

#include"indicant.h"
#include<QObject>
#include<QKeyEvent>

class IndicantMenu: public Indicant
{
public:
    IndicantMenu(int x);
    void move(int direction) final;
    void reset() final;
};

#endif // INDICANT_MENU_H
