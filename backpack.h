#ifndef BACKPACK_H
#define BACKPACK_H

#include<QVector>
#include"consumable.h"
#include"equipable_armor.h"
#include"equipable_shield.h"
#include"equipable_sword.h"

class Backpack
{
private:
    QVector<Item*> items;
public:
    Backpack();
    QVector<Item*> getItems();
};

#endif // BACKPACK_H
