#include"equipable_armor.h"

EquipableArmor::EquipableArmor(int attack, int defence): Equipable(attack, defence)
{
    price=100;
    name="Wooden Armor";
    pixmap=QPixmap(":/images/items.png").copy(0, 32, 32, 32);
}
