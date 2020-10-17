#include"indicant_titlescreen.h"
#include<QDebug>

IndicantTittleScreen::IndicantTittleScreen(int x): Indicant(x)
{
    position=0;
    setPos(this->x(), 175);
}
int IndicantTittleScreen::getPosition()
{
    return position;
}
void IndicantTittleScreen::move(int direction)
{
    position+=direction;
    if(position==-1)
    {
        position=2;
        moveBy(0, 200);
    }
    else if(position==3) reset();
    else moveBy(0, direction*100);
}
void IndicantTittleScreen::reset()
{
    position=0;
    setPos(300, 175);
}
