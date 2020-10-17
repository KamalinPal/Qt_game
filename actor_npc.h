#ifndef ACTOR_NPC_H
#define ACTOR_NPC_H

#include"actor.h"

class ActorPlayer;

class ActorNpc: public Actor
{
protected:
    QVector<QString> text;
public:
    ActorNpc();
    virtual QVector<QString> talk(ActorPlayer *);
};

#endif // ACTOR_NPC_H
