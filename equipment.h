#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include"equipable_armor.h"
#include"equipable_shield.h"
#include"equipable_sword.h"

class Equipment
{
private:
    EquipableArmor *armor;
    EquipableSword *sword;
    EquipableShield *shield;
public:
    Equipment();
};

#endif // EQUIPMENT_H
