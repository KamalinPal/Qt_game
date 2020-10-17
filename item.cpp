#include"item.h"

Item::Item()
{

}
Item::~Item()
{

}
int Item::getPrice()
{
    return price;
}
int Item::getAmount()
{
    return amount;
}
QString Item::getName()
{
    return name;
}
QPixmap Item::getPixmap()
{
    return pixmap;
}
