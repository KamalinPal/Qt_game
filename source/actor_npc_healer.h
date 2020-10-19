#ifndef ACTOR_NPC_HEALER_H
#define ACTOR_NPC_HEALER_H

#include"actor_npc.h"

class NpcHealer: public ActorNpc
{
public:
    NpcHealer();
    QVector<QString> talk(ActorPlayer *player) final;
};

#endif // ACTOR_NPC_HEALER_H
