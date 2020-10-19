#include"actor.h"

Actor::Actor()
{

}
QPainterPath Actor::shape() const
{
    QPainterPath p;
    p.addRect(0, 26, 25, 16);
    return p;
}
void Actor::changeExp(int delta)
{
    exp+=delta;
}
int Actor::changeHp(int delta)
{
    int prevHp=hp;
    hp+=delta;
    if(hp>maxHp) hp=maxHp;
    return abs(hp-prevHp);
}
int Actor::changeMp(int delta)
{
    int prevMp=mp;
    mp+=delta;
    if(mp>maxMp) mp=maxMp;
    return abs(mp-prevMp);
}
void Actor::changeAttack(int delta)
{
    attack+=delta;
}
void Actor::changeDefence(int delta)
{
    defence+=delta;
}
void Actor::setDirection(int direction)
{
    this->direction=direction;
    if(direction==0) setPixmap(sheet.copy(0, 144, 32, 48));
    if(direction==1) setPixmap(sheet.copy(0, 96, 32, 48));
    if(direction==2) setPixmap(sheet.copy(0, 0, 32, 48));
    if(direction==3) setPixmap(sheet.copy(0, 48, 32, 48));
}
QString Actor::getName()
{
    return name;
}
int Actor::getExp()
{
    return exp;
}
int Actor::getHp()
{
    return hp;
}
int Actor::getMp()
{
    return mp;
}
int Actor::getAttack()
{
    return attack;
}
int Actor::getDefence()
{
    return defence;
}
int Actor::getDirection()
{
    return direction;
}
