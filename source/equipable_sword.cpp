#include"equipable_sword.h"

EquipableSword::EquipableSword(int attack, int defence): Equipable(attack, defence)
{
    price=50;
    name="Wooden Sword";
    pixmap=QPixmap(":/images/items.png").copy(0, 128, 32, 32);
}
