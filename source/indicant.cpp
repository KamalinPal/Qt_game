#include"indicant.h"
#include<QtDebug>

Indicant::Indicant(int x)
{
    setPos(x, 0);
    setPixmap(QPixmap(":/images/arrow.png"));
    setZValue(20);
}
Indicant::Indicant(int x, int length, int multiplier, int offset, qreal scale)
{
    setX(x);
    this->length=length;
    this->multiplier=multiplier;
    this->offset=offset;
    reset();
    setScale(scale);
    setPixmap(QPixmap(":/images/arrow.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setZValue(20);
}
void Indicant::move(int direction)
{
    position=((position+direction)%length+length)%length;
    setPos(x(), position*multiplier+offset);
}
void Indicant::reset()
{
    position=0;
    setY(offset);
}
int Indicant::getPosition()
{
    return position;
}
