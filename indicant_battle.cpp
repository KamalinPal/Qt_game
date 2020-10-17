#include"indicant_battle.h"

IndicantBattle::IndicantBattle(int x): Indicant(x)
{
    position=0;
    setScale(0.3);
    setPos(this->x(), 434);
    setZValue(10);
}
void IndicantBattle::move(int direction)
{
    if(direction==0)
    {
        if(position==0||position==1) moveBy(0, 30);
        else moveBy(0, -30);
        position=(position+2)%4;
    }
    else
    {
        if(position==0||position==2)
        {
            moveBy(80, 0);
            ++position;
        }
        else
        {
            moveBy(-80, 0);
            --position;
        }
    }
}
void IndicantBattle::reset()
{
    setPos(620, 434);
    position=0;
}
