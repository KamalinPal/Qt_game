#ifndef EQUIPABLE_SWORD_H
#define EQUIPABLE_SWORD_H

#include"equipable.h"
#include"item.h"

class EquipableSword: public Equipable
{
public:
    EquipableSword(int attack, int defence);
};

#endif // EQUIPABLE_SWORD_H
