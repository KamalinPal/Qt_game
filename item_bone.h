#ifndef ITEM_BONE_H
#define ITEM_BONE_H

#include"item.h"

class ItemBone: public Item
{
public:
    ItemBone();
    QString use(ActorPlayer *);
};

#endif // ITEM_BONE_H
