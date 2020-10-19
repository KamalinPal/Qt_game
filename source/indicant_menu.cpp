#include"indicant_menu.h"
#include<QDebug>

IndicantMenu::IndicantMenu(int x): Indicant(x)
{
    position=0;
    setScale(0.5);
    setPos(this->x(), 138);
}
int IndicantMenu::getPosition()
{
    return position;
}
void IndicantMenu::move(int direction)
{
    position=((position+direction)%4+4)%4;
    setPos(300, (position+1)*100+38);
}
void IndicantMenu::reset()
{
    position=0;
    setPos(300, 138);
}
