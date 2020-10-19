#ifndef EQUIPABLE_ARMOR_H
#define EQUIPABLE_ARMOR_H

#include"equipable.h"
#include"item.h"

class EquipableArmor: public Equipable
{
public:
    EquipableArmor(int attack, int defence);
};

#endif // EQUIPABLE_ARMOR_H
