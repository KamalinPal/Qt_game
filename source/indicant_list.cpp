#include"indicant_list.h"

IndicantList::IndicantList(int x): Indicant(x)
{

}
int IndicantList::getPosition()
{
    return position;
}
void IndicantList::move(int direction)
{
    position=((position+direction)%length+length)%length;
    setPos(x(), position*multiplier+offset);
}
void IndicantList::reset()
{
    position=0;
}
