#ifndef EQUIPABLE_H
#define EQUIPABLE_H

#include"item.h"

class Equipable: public Item
{
protected:
    bool equipped;
    int attack;
    int defence;
public:
    Equipable(int attack, int defence);
    virtual ~Equipable();
    QString use(ActorPlayer *player) final;
};

#endif // EQUIPABLE_H
