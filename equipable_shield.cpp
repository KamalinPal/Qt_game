#include"equipable_shield.h"

EquipableShield::EquipableShield(int attack, int defence): Equipable(attack, defence)
{
    price=50;
    name="Wooden Shield";
    pixmap=QPixmap(":/images/items2.png").copy(320, 192, 32, 32);
}
