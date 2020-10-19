#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include"item.h"

class Consumable: public Item
{
protected:
    int effect;
public:
    Consumable();
};

#endif // CONSUMABLE_H
