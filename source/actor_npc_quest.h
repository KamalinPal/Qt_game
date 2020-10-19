#ifndef ACTOR_NPC_QUEST_H
#define ACTOR_NPC_QUEST_H

#include"actor_npc.h"

class NpcQuest: public ActorNpc
{
public:
    NpcQuest();
    QVector<QString> talk(ActorPlayer *player) final;
};

#endif // ACTOR_NPC_QUEST_H
