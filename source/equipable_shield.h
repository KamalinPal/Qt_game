#ifndef EQUIPABLE_SHIELD_H
#define EQUIPABLE_SHIELD_H

#include"equipable.h"
#include"item.h"

class EquipableShield: public Equipable
{
public:
    EquipableShield(int attack, int defence);
};

#endif // EQUIPABLE_SHIELD_H
